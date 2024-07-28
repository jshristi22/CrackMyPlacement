
// Solved on gfg
// Question
// https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/
// Answer
// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0

class Solution {
  private:
    void dfs(vector<vector<int>> grid, vector<vector<int>>& vis,
            int row, int col, vector<pair<int,int>>& vec, int rowBase, int colBase){
        
        int n = grid.size();
        int m = grid[0].size();
        int delRow[]= {-1,0,1,0};
        int delCol[]= {0,1,0,-1};
        
        vis[row][col] = 1;
        vec.push_back({row - rowBase,col - colBase});
        // visiting neighbor islands
        for(int i = 0; i<4; i++){
            int nr = row + delRow[i];
            int nc = col + delCol[i];
            
            if(nr >= 0 && nc >= 0 &&  nr <n && nc < m
                && !vis[nr][nc] && grid[nr][nc] == 1
            ){
                dfs(grid, vis, nr, nc, vec, rowBase, colBase);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(grid, vis, i, j, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};