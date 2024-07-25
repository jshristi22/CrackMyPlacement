#include<bits/stdc++.h>
// solved on leetcode
// https://leetcode.com/problems/climbing-stairs/submissions/1333271190/

class Solution {
    private:
    
    int f(int n, vector<int> &dp){
        if(n<0) return 0;
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};
