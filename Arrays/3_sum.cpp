
// leetcode
// https://leetcode.com/problems/3sum/description/

vector<vector<int>> threeSum(vector<int>& nums) {
    // TC: O(n log n) * O(n^2);
    // SC: O(no. of triplets);
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end()); //O(n log n)
    for(int i = 0;i<n; i++){ // O(n)
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){ //O(n)
            int sum = nums[i] + nums[j] + nums[k];
            if(sum<0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                vector<int> temp = {nums[i] , nums[j], nums[k]};
                ans.push_back(temp);
                j++, k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }                
        }
    }
    return ans;

}