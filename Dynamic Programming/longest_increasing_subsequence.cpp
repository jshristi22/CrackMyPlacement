// solved on leetcode
// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
    private:
    int f(int i , int prev, vector<int> nums, vector<vector<int>>& dp, int n){
        if(i == n)  return 0;        
        
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        
        int notPick = 0  + f(i+1, prev , nums, dp, n);
        int pick = 0;
    
        if(prev == -1 || nums[i] > nums[prev])
            pick = 1 + f(i+1, i, nums, dp, n);       
        return dp[i][prev + 1] = max(pick, notPick);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();        
        vector<int> next(n+1, 0), cur(n+1, 0);
        // vector<vector<int>> dp(n + 1, vector<int>(n+1, 0));

        for(int i = n-1; i>=0; i--){
            for(int prev = i-1; prev >=-1; prev--){
                int notPick = 0  + next[prev + 1];
                int pick = 0;            
                if(prev == -1 || nums[i] > nums[prev])
                    pick = 1 + next[i + 1];
                cur[prev + 1] = max(pick, notPick);
            }
            next = cur;
        }

        return next[0];        
    }
};