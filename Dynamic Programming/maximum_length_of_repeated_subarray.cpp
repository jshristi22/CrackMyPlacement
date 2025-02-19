// solve on leetcode
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
// longest common subarray between two given arrays

 int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size(); 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxi = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){                
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = 0;
                }
                maxi = max(maxi, dp[i][j])                ;
            }            
        }

        return maxi;                
    }