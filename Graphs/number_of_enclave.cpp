#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG
// https://www.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

 int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if( i == 0 || j ==0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }   
        }
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i<4; i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                
                if(nr >= 0 && nc >= 0 && nr <n && nc <m 
                    && !vis[nr][nc] && grid[nr][nc] == 1){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
            }
        }
        
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }