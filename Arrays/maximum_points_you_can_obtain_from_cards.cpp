
// leetcode
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

int maxScore(vector<int>& nums, int k) {
    int maxSum = 0;
    int n = nums.size();

    for(int i = 0; i<n; i++){
        if(i == k) break;
        maxSum += nums[i];
    }

    int i = k-1;
    int j = n -1;
    int sum = maxSum;
    while(i >= 0 && n - j <= k){            
        sum = sum - nums[i] + nums[j];
        maxSum = max(maxSum, sum);            
        i--, j--;
    }
    return maxSum;
}