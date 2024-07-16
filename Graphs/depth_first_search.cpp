#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG
class Solution {    
    private:
        void dfs(vector<int> adj[], vector<int>& visited, vector<int>& ansList, int startNode){
            visited[startNode] = 1;
            ansList.push_back(startNode);
            // Checking neighbors
            for(auto it: adj[startNode]){
                if(!visited[it]){
                    dfs(adj, visited, ansList, it);
                }
            }
        }
        
    public:
        // Function to return a list containing the DFS traversal of the graph.
        vector<int> dfsOfGraph(int V, vector<int> adj[]) {
            vector<int> visited(V,0);
            vector<int> ansList;
            dfs(adj, visited, ansList, 0);
            return ansList;        
        }
};