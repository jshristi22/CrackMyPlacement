#include<bits/stdc++.h>
// solved on gfg
// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    int kr = N+1-KnightPos[1];
    int kc = KnightPos[0];
    
    int tr = N+1 - TargetPos[1];
    int tc = TargetPos[0];
    
    if(tc == kc && tr == kr) return 0;

    vector<vector<int>> vis(N+1, vector<int>(N +1, 0));
    vis[kr][kc] =  1;;
    
    // {steps, {r,c}}
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{kr, kc}});
    
    
    int delr[] = {-1,-1,1,1,2,2, -2, -2};
    int delc[] = {-2,2,-2,2,-1,1, 1, -1};
    while(!q.empty()){
        int steps = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
    
        // visit all the possible positions
        for(int i = 0; i< 8; i++){
            int newr = r + delr[i];
            int newc = c + delc[i];
            if(newr>= 1 && newc >=1 && newr<=N && newc<=N && vis[newr][newc] == 0){
                if(newr == tr && newc == tc ) 
                    return steps +1;
                
                vis[newr][newc] = 1;
                q.push({steps+1,{newr, newc}});
            }
        }
    }
    
}