
import <bits/stdc++.h>
using namespace std;

// Solved on gfg
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

class Solution{

  private:
    bool detectUsingBSF(vector<int> adj[], int vis[], int node){
        vis[node] = 1;
        queue<pair<int,int>> q;
        // came from nowhere
        q.push({node, -1});
        
        while(!q.empty()){
            int currentNode = q.front().first;
            int parentNode = q.front().second;
            q.pop();
            
            for(auto it: adj[currentNode]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, currentNode});
                }else{
                    if(it != parentNode)
                        return true;
                }
            }
        }
        return false;
    }
    
    bool detectUsingDSF(vector<int> adj[], int vis[], int node, int parentNode){
        vis[node] = 1;
        
        // visiting it's neighbors
        for(auto it: adj[node]){
            if(!vis[it]){   
                if(detectUsingDSF(adj, vis, it, node))
                    return true;
            }else{
                if(it != parentNode){
                    return true;
                }
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]= {0};
        for(int i = 0; i<V; i++){
            if(!vis[i]){                
                // if(detectUsingBSF(adj, vis, i)){
                //     return true;
                // }
                if(detectUsingDSF(adj, vis, i, -1)){
                    return true;
                }
            }
        }
        return false;
    }
};