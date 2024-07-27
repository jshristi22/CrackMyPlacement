#include<bits/stdc++.h>
// solved on gfg
// https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal

class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            
            for(int i = 0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findUPar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionBySize(int u, int v){
            int ulp_v = findUPar(v);
            int ulp_u = findUPar(u);
            if(ulp_v == ulp_u) return ;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};


class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int totalStones = 0;
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            totalStones++;
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        for(auto it: stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
            ds.unionBySize(row, col);
        }
        
        
        int components = 0;
        for(auto it: stoneNodes){
            if(ds.parent[it.first] == it.first ) {
                components++;
            }
        }
        return totalStones - components;
    }
};
