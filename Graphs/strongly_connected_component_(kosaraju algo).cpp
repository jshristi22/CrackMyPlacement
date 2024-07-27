#include<bits/stdc++.h>

// solved on gfg
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution{

    /*
    Algo states:
    1. Sort all the edges acc. to finishing time.(store in stack)
    2. reverse all the edges
    3. Do dfs on every node in stack and count the number of times dfs was call.
    */
    
private:
void dfsWithStack(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[node] = 1;
    
    // visiting neighbor, if not already visited
    for(auto it: adj[node]){
        if(!vis[it]){
            dfsWithStack(it, vis, adj, st);
        }
    }
    st.push(node);
};
void dfs(int node, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    
    // visiting neighbor, if not already visited
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj);
        }
    }
};


public:
//Function to find number of strongly connected components in the graph.
int kosaraju(int v, vector<vector<int>>& adj)
{
    int V = v;
    vector<int> adjMat[V];
    vector<int> vis(V, 0);
    stack<int> st;
    
    // Making adj graph
    for(int i = 0; i<V; i++){
        for(auto &jt: adj[i]){
            adjMat[i].push_back(jt);
        }
    }
    
    
    // sorting nodes
    for(int i = 0 ; i <V ;i++){
        if(!vis[i]){
            dfsWithStack(i, vis, adjMat, st);
        }
    }
    
    // // reverse edges
    vector<int> adjT[V];
    for(int i = 0; i<V; i++){
        vis[i] = 0;
        for(auto it: adjMat[i]){
            adjT[it].push_back(i);
        }
    }
    
    
    int cnt = 0;
    while(!st.empty()){
        int i =  st.top();
        st.pop();
        if(!vis[i]){
            cnt++;
            dfs(i, vis, adjT);
        }
    }
    return cnt;
};