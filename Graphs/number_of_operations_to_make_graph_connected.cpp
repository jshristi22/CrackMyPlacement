#include<bits/stdc++.h>
// solved on gfg
// https://www.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph

class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            
            for(int i = 0; i<n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findUPar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }
        
        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            
            if(ulp_u < ulp_v){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtra = 0;
        for(auto it: edge){
            int u = it[0]; int v = it[1];
            
            if(ds.findUPar(u) != ds.findUPar(v))
                ds.unionBySize(it[0], it[1]);
            else{
                cntExtra ++;
            }
        }
        int cntComponent = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i] == i) cntComponent ++;
        }
        
        
        if(cntExtra >= (cntComponent -1)) return cntComponent -1;
        else return -1;
    }
};