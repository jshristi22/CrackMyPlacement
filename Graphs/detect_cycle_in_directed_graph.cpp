#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

 private:
    bool runDfs(int node, vector<int>& vis,  vector<int>& pathVis,  vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        // visiting neighbors
        for(auto it: adj[node]){
            // if not visited
            if(!vis[it]){
                if(runDfs(it, vis, pathVis, adj)) return true;
            }else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for(int i = 0; i< V; i++){
            if(!vis[i]){
                if(runDfs(i, vis, pathVis, adj)){
                    return true;
                }
            }
        }
        return false;
    }