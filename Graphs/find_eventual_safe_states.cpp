
#include<bits/stdc++.h>
using namespace std;
// Solved it on leetcode
// https://leetcode.com/problems/find-eventual-safe-states//


class Solution {
    private:
    vector<int> topoSort(int V, vector<int> adj[]) {    
        vector<int> ans;    
        int inDegree[V];

        for (int i = 0; i < V; ++i) {
            inDegree[i] = 0;
        }

        for(int i = 0; i<V; i++){
            for(auto it: adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            //visit neighbor and decrease degree by 1
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];

        for(int i = 0; i<V; i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                cout<<it<<" :"<<i;
            }
        }

        return topoSort(V, adj);        
    }
};