#include<bits/stdc++.h>

// solved on leetcode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
    private:
    int f(int i , int isBuy, vector<int> prices, vector<vector<int>> dp, int n){
        if(i == n) return 0;
        if(dp[i][isBuy] != -1) return dp[i][isBuy];
        int profit = 0;
        if(isBuy){
            profit =  max(-prices[i] + f(i+1, 0, prices, dp, n), f(i+1,1, prices, dp, n));
        }else{
            profit = max(prices[i] + f(i+1, 1, prices, dp, n), f(i+1,0, prices, dp, n));
        }
        return dp[i][isBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i = n-1; i>=0; i--){
            for(int isBuy = 0; isBuy <=1; isBuy++){
                int profit = 0;
                if(isBuy){
                    profit =  max(-prices[i] + dp[i+1][ 0], dp[i+1][1]);
                }else{
                    profit = max(prices[i] + dp[i+1][ 1], dp[i+1][0]);
                }
                dp[i][isBuy] = profit;
            }
        }
        return dp[0][1];
    }
};