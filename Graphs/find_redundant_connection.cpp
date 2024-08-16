// https://leetcode.com/problems/redundant-connection/submissions/1357457178/

class DisjointSet{
    private: 
    vector<int> parent;
    vector<int> size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node){
        if(parent[node] == node){
            return node;
        }else{
            return parent[node] = findUParent(parent[node]);
        }
    }
    void unionBySize(int u, int v){
        int ulp_u= findUParent(u);
        int ulp_v= findUParent(v);

        if(size[ulp_u] <= size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
private:
    bool dfs(int node, int parent, vector<int> adj[], 
            vector<int>& vis)
    {
        vis[node] = 1;
        // visit neighbors
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, node, adj, vis)) return true;
            }else{
                if(it != parent){                   
                    return true;
                }
            }
        }        
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(auto it: edges){
            if(ds.findUParent(it[0]) == ds.findUParent(it[1])){
                return it;
            }else{
                ds.unionBySize(it[0], it[1]);
            }
        }
        return {};
        // vector<int> adj[n+1];        
        // vector<int> vis(n+1, 0);

        // for(auto edge: edges){
        //     // adding one edges
        //     fill(vis.begin(), vis.end(), 0);
        //     adj[edge[0]].push_back(edge[1]);
        //     adj[edge[1]].push_back(edge[0]);            
        //     // checking if cycle is created with this edge of not
        //     if(dfs(edge[0], -1, adj, vis)) {
        //         return edge;
        //     }
        // }
        
        // return {};
    }
};
