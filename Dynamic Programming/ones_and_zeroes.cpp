
#include<bits/stdc++.h>
// solved on leetcode
// https://leetcode.com/problems/ones-and-zeroes/

int findMaxForm(vector<string>& strs, int m, int n) {
    int size = strs.size();
    // dp[i][j] will be the maximum number of strings that can be formed with i zeros and j ones
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (const string& s : strs) {
        int ones = 0;
        int zeros = 0;
        for (char c : s) {
            if (c == '1') ones++;
            else if (c == '0') zeros++;
        }
        
        // We need to iterate backwards to ensure that each string is only considered once
        for (int i = m; i >= zeros; --i) {
            for (int j = n; j >= ones; --j) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
            }
        }
    }
    
    return dp[m][n]; 
}