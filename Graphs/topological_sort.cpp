
#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG
// https://www.geeksforgeeks.org/problems/topological-sort/1


class Solutions{
    private:
        void dfs (int node, int vis[], stack<int>& st, vector<int> adj[]){
            vis[node] = 1;
            
            for(auto it: adj[node]){
                if(!vis[it]) dfs(it, vis, st, adj);
            }
            st.push(node);
        }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
    int vis[V] = {0};
    stack<int> st;
    vector<int> ans;
    // Using DFS
    // for(int i = 0; i<V; i++){
    //     if(!vis[i]) dfs(i, vis, st, adj);
    // }
    
    // while(!st.empty()){
    //     int ele  = st.top();
    //     st.pop();
    //     ans.push_back(ele);
    // }
    // return ans;
    
    //Using BFS (modified version) Kahn's algorithm
    /*
    1. We maintain an array of inDegree for every node.
    2. For nodes having 0 inDegree, we push them to ans vector.
    3. We check reduce it's neighbor's inDegree by 1(as the current node's edge is counted)
    4. check if it's inDegree is 0 and repeat the above process
    */
    
    int inDegree[V]={0};
    
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
    return ans;
    }
};