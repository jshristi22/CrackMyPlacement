// leetcode
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

 int countSquares(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i<n;i++) dp[i][0] = arr[i][0];
        for(int j = 0; j<m;j++) dp[0][j] = arr[0][j];
        
        int sum = 0;
        
        for(int i = 1; i<n; i++){
        for (int j = 1; j < m; j++) {
            if(arr[i][j] == 1)
            dp[i][j] = 1 + min(dp[i-1][j],
                            min(dp[i-1][j-1], dp[i][j-1])
                        );
        }
        }
        for(int i = 0; i<n; i++){
        for (int j = 0; j < m; j++) {        
            sum += dp[i][j];
        }
        }
        return sum;
    }