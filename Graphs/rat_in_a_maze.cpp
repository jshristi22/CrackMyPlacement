#include<bits/stdc++.h>
using namespace std;
// Solved it on gfg
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


void dfs(int r, int c, int n, int m, vector<vector<int>> &mat, 
        vector<vector<int>>& vis, string &path, vector<string>& ans){
    
    if(r == n-1 && c == m-1) {
        ans.push_back(path);
        return;
    }
    
    vis[r][c] =1;
    // visit neighbors
    int delr[] = {1,0,0,-1};
    int delc[] = {0,-1,1,0};
    string dir[] = {"D", "L",  "R", "U"};
    
    for(int i = 0; i<4; i++){
        int newr = r+ delr[i];
        int newc = c+ delc[i];
        
        if(newr >= 0 && newr < n && newc >= 0 && newc < m
            && mat[newr][newc] == 1 && vis[newr][newc] == 0
        ){
            path += dir[i];
            
            dfs(newr,newc,n,m,mat,vis,path, ans);
            path.pop_back();
    
        }
    }
    vis[r][c] = 0;
}  
vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(m, 0)) ;
    
    string path = "";
    if(mat[0][0] == 1)
        dfs(0,0,n,m, mat, vis, path, ans);
    
    return ans;
}