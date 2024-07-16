#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    vector<int> ansList;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    
    while(!q.empty()){
        int currentNode = q.front();
        ansList.push_back(currentNode);
        q.pop();
        
        for(auto it: adj[currentNode]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return ansList;
}
