
//  leetcode
// https://leetcode.com/problems/burst-balloons/

long long f(int i, int j, vector<int> &nums, vector<vector<int>>& dp){
    if(i  > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    long long ans = INT_MIN;
    for(int ind = i; ind<=j; ind++){
        long long coins = nums[i-1] * nums[ind] * nums[j+1] 
                    + f(i, ind-1, nums, dp) + f(ind+1, j, nums, dp);
        ans = max(ans, coins);
    }
    return dp[i][j] = ans;
}


int maxCoins(vector<int>& nums) {
    // track the bursting balloons in reverse order
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return f(1, n, nums, dp);
}