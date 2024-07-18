
#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


    int maxProfit(vector<int>& prices) {
        int minSoFar= prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i = 0; i<n; i++){
            int profit = 0;
            if(minSoFar > prices[i]){
                minSoFar = prices[i];
            }

            // calculate the current profit
            profit= prices[i] - minSoFar;

            // calculating the max profit
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
        }