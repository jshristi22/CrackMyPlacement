#include<bits/stdc++.h>
// solved on gfg
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> vis(V, 0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum+= wt;
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int adjWt = it[1];
                if(!vis[adjNode]){
                    pq.push({adjWt, adjNode});
                }
            }
        }
        return sum;
    }