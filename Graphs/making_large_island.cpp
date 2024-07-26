
// solved on leetcode
// https://leetcode.com/problems/making-a-large-island/submissions/1334370003/


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
private:
bool isValid(int newr, int newc, int n){
    return newr >= 0 && newr < n && newc >= 0 && newc < n;
};

public:
    int largestIsland(vector<vector<int>>& grid) {
         int n = grid.size();
        DisjointSet ds(n*n);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0) continue;
                
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, 1, 0, -1};
                for(int k = 0 ; k<4; k++){
                    int newr = i + delr[k];
                    int newc = j + delc[k];
                    
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int node = i * n + j;
                        int adjNode = newr * n + newc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        
        int mx = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) continue;
                
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, -1, 0, 1};
                
                set<int> st;
                for(int k = 0 ; k<4; k++){
                    int newr = i + delr[k];
                    int newc = j + delc[k];
                    if(isValid(newr, newc, n)){
                        if(grid[newr][newc] == 1)
                            st.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int s = 0;
                for(auto it: st){
                    s += ds.size[it];
                }
                
                mx = max(mx, s+1);
            }
        }
        
        for(int cn = 0; cn < n * n; cn++){
            mx = max(mx, ds.size[ds.findUPar(cn)]);
        }
        
        return mx;
    }    
};