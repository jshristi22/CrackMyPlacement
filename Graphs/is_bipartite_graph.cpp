#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG
// https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

private:

    // using  bfs
    bool bfs(vector<int>adj[], vector<int> &vis, int startNode){
        // filling with 0 color
        vis[startNode] = 0;
        queue<pair<int, int>> q;
        q.push({startNode, 0});
        
        // Visiting neighbor
        while(!q.empty()){
            int currentNode = q.front().first;
            int currentColor = q.front().second;
            q.pop();
            
            for(auto it: adj[currentNode]){
                if(vis[it] == -1){
                    int color = currentColor == 0? 1: 0;
                    vis[it] = color;
                    q.push({it, color});
                }else{
                    if(vis[it] == currentColor)
                    // No, it is not bipartite
                        return false;
                }
            }
        }
        // yes it is bipartite
        return true;
        
    }

    // usign dfs
    bool dfs(vector<int>adj[], vector<int> &vis, int startNode, int color){
        vis[startNode] = color;
        
        // traversing the adjacent
        for(auto it: adj[startNode]){
            if(vis[it] == -1){
                if(!dfs(adj, vis, it, color == 0? 1: 0)) return false;
            }
            else{
                if(vis[it] == color){
                    return false;
                }
            }
        }
        return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V, -1);
	    
	    for(int i = 0; i<V; i++){
	        if(vis[i] == -1){
    	        if(!bfs(adj, vis, i))
    	            return false;

    	        // if(!dfs(adj, vis, i))
    	        //     return false;
	        }
	    }
	    return true;
	}
