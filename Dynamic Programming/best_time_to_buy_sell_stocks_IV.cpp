#include<bits/stdc++.h>

// solved on leetcode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1333893771/

 vector<vector<int>> after(2, vector<int>(k+1, 0))   ;
    vector<vector<int>> current(2, vector<int>(k+1, 0))   ;

    for(int i = n-1; i>=0; i--){
        for(int j = 0; j<=1; j++){
            for(int cap = 1; cap<=k; cap++){
                if(j){
                    current[j][cap] = max(
                        -prices[i] + after[0][cap], 
                        after[1][cap]);
                }else{
                    current[j][cap] = max(
                        prices[i] + after[1][cap - 1], after[0][cap]);
                }
            }
        }
        after= current;
    }
    
    return after[1][k];