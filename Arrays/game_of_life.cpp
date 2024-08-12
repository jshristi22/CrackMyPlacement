// leetcode
// https://leetcode.com/problems/game-of-life/description/

class Solution {
    private: 
        bool checkZeroesNeighbors(int r, int c, int n, int m, vector<vector<int>>& board){
            int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
            int liveCells = 0;
            for(int i = 0; i<8; i++){
                int newr = r + delRow[i];
                int newc = c + delCol[i];
                if(newr>=0 && newc>=0 && newr < n && newc < m){                    
                    if(board[newr][newc] == 1)
                        liveCells++;
                }
            }
            return liveCells== 3;
        }
        bool checkOnesNeighbors(int r, int c, int n, int m, vector<vector<int>>& board){
            int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
            int liveCells = 0;            
            for(int i = 0; i<8; i++){
                int newr = r + delRow[i];
                int newc = c + delCol[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m){                    
                    if(board[newr][newc] == 1)
                        liveCells++;                    
                }
            }
            if(liveCells < 2 || liveCells > 3) return false;
            return true;
        }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for(int r = 0; r < n; r++)   {
            for(int c = 0; c<m; c++){
                if(board[r][c] == 0){
                    if(checkZeroesNeighbors(r, c, n, m, board))
                        temp[r][c] = 1;                        
                }
                else{
                    if(checkOnesNeighbors(r, c, n, m, board))
                        temp[r][c] = 1;                        
                }
            }
        }

        for(int r = 0; r < n; r++)   {
            for(int c = 0; c<m; c++){
                board[r][c] = temp[r][c];
            }
        }
    }
};