
// leetcode
// https://leetcode.com/problems/word-search/

class Solution {
    private: 
    // Failing test case 73 as, I'm not using recursion & backtracking to solve this issue
    bool findWord(int r, int c, vector<vector<char>>& board, string word, int wordIdx){
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        queue<pair<int, int>> q;
        q.push({r, c});      
        vis[r][c] = 1;                   
                
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        
         while(!q.empty() ){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            bool flag = false;
            for(int i = 0; i<4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr >= 0 && nr <row && nc>= 0 && nc < col){
                    if(!vis[nr][nc] && word[wordIdx] == board[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                        flag = true;
                    }
                }
            }
            if(flag) wordIdx++;
            if(wordIdx == word.size())
                return true;
        }
        
        return false;
    }
    // Using recursion and backtracking
    bool findWordII(vector<vector<char>> &board, string word, int row, int col, 
    int wordIdx, int m, int n) {
       
        if (wordIdx == word.length())
            return true;
       
        //the required character
        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != 
        word[wordIdx] or board[row][col] == '!')
            return false;
       
        char c = board[row][col];
        board[row][col] = '!';
       
        bool top = findWordII(board, word, row - 1, col, wordIdx + 1, m, n);       
        bool right = findWordII(board, word, row, col + 1, wordIdx + 1, m, n);       
        bool bottom = findWordII(board, word, row + 1, col, wordIdx + 1, m, n);       
        bool left = findWordII(board, word, row, col - 1, wordIdx + 1, m, n);
        board[row][col] = c;
        return top || right || bottom || left;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int wordIdx = 0;
       
        for(int r = 0; r<row; r++ ){
            for(int c = 0; c<col ; c++ ){
                if(word[wordIdx] == board[r][c]){
                    // if(findWord(r, c, board, word, wordIdx + 1)) 
                    //     return true;
                     if (findWordII(board, word, r, c, 0, row, col))
                        return true;
                }
            }
        }               
        return false;
        
    }
};