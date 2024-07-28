
// solved on gfg
// Question
// https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/
// Solution:
// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

class Solution{
    
    private:
    void dfs(vector<vector<char>> mat, vector<vector<int>>& vis, int r, int c){
        vis[r][c] = 1;
        int delRow[] = {-1, 0, 1,0};
        int delCol[] = {0, 1,0, -1};
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<4; i++){
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            
            if(nr >=0 && nc >=0 && nr < n && nc < m 
                && !vis[nr][nc] && mat[nr][nc] == 'O'
            )
                dfs(mat, vis, nr, nc);
        
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m,0));
        // visiting boundaries
        for(int j = 0; j < m; j++){
            
            // first row
            if(!vis[0][j] && mat[0][j] == 'O')
                dfs(mat, vis, 0, j);
                
             // Last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O')
                dfs(mat, vis, n-1, j);
        }
 
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && mat[i][0] == 'O')
                dfs(mat, vis, i, 0);
            if(!vis[i][m-1] && mat[i][m-1] == 'O')
                dfs(mat, vis, i, m-1);
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};