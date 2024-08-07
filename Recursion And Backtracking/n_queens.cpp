
// leetcode
// https://leetcode.com/problems/n-queens/

class Solution {
private:
    bool isQueenSafe(int r, int c, vector<string> board, int n){
        int row = r, col = c;
        while( r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;            
            r--, c--;
        }

        r = row;
        c = col;
        while( c >= 0){
            if(board[r][c] == 'Q') return false;            
            c--;
        }

        r = row;
        c = col;
        while( r < n && c >= 0){
            if(board[r][c] == 'Q') return false;            
            r++, c--;
        }
        
        return true;

    }
private:
    void f(int col, int n, vector<string>& board, 
    vector<vector<string>>& ans, vector<int>& prevRow , 
    vector<int>& prevUpperDiagonal, vector<int>& prevLowerDiagonal){
        // base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row <n; row++){
            // if(isQueenSafe(row, col, board, n))

            if(prevRow[row] == 0 
                && prevUpperDiagonal[(n-1 + col -row)] == 0 
                && prevLowerDiagonal[row+col] == 0)
            {
                board[row][col] = 'Q';
                // updating hash map
                prevRow[row] = 1;
                prevUpperDiagonal[(n-1 + col -row)] = 1;
                prevLowerDiagonal[row+col] = 1;
                // recursive call
                f(col+1, n, board, ans, prevRow, prevUpperDiagonal, prevLowerDiagonal);
                // backtracking
                board[row][col] = '.';                
                prevRow[row] = 0;
                prevUpperDiagonal[(n-1 + col -row)] = 0;
                prevLowerDiagonal[row+col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');
        vector<int> prevRow(n, 0);
        vector<int> prevUpperDiagonal(2*n - 1, 0);
        vector<int> prevLowerDiagonal(2*n - 1, 0);
        
        for(int i = 0; i<n; i++){
            board.push_back(s);
        }
        f(0, n, board, ans, prevRow, prevUpperDiagonal, prevLowerDiagonal);
        return ans;
    }
};