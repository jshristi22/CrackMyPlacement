#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

 private:
 
    bool topologicalSort(int V, vector<int> adj[]){
        int indegree[V] = {0};
        vector<int> order;
        int count = 0;
        
        for(int i = 0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            count++;
            q.pop();
            
            // visit neighbors
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return !(count == V);
        
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {        
        return topologicalSort(V, adj);
    }