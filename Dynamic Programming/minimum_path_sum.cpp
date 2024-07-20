#include <bits/stdc++.h> 
using std namespace;

// Solved on Codestudio
// https://www.naukri.com/code360/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

// Using recursion
/*
TC: 2^(n+m)
SC: O(n*m) + O(n);
*/
int findMinPath(int r, int c, vector<vector<int>>& grid, 
                vector<vector<int>>& dp){
    // base case 
    if(r == 0 && c == 0) return grid[r][c];

    if(r < 0 || c < 0) return 1e9;
        
    if(dp[r][c] != -1) return dp[r][c];

    int up = grid[r][c] + findMinPath(r - 1, c,  grid,dp);
    int left = grid[r][c] + findMinPath(r, c -1,  grid,dp);

    return dp[r][c] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    // For memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    
    // For tabulation with 2D matrix;
    // vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // With Space optimization
    vector<int> prev(m, 0);

    for(int i = 0; i < n; i++){
      vector<int> temp(m, 0);
      for (int j = 0; j < m; j++) {
          if( i == 0 && j == 0 ) temp[j] = grid[0][0];
          else{
            int up = grid[i][j];
            int left = grid[i][j];
            if( i > 0) up = grid[i][j] + prev[j];
            else up += 1e9;
            if( j > 0) left = grid[i][j] + temp[j - 1];
            else left += 1e9;
            temp[j] = min (up, left);
          }
      }
      prev = temp;
    }
    return prev[m-1];
    // return  findMinPath(n-1, m-1, grid, dp);
}