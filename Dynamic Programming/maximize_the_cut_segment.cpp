// solved on gfg
// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

class Solution{
    private:
    int f(int i, int arr[], int target, vector<vector<int>>& dp){
        if(target == 0) 
            return 0;
        if(i < 0) {
            return -1e9;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int notPick = 0 + f(i-1, arr, target, dp);
        int pick = -1e9;
        
        if(arr[i] <= target){
            pick = 1 +  f(i, arr, target - arr[i], dp);
        }
        return dp[i][target] = max(pick, notPick);
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //       index, arr, target
        int arr[3] = {x,y,z};
        vector<vector<int>> dp(3, vector<int> (n+1, -1));
        int ans = f(2, arr, n, dp);
        if(ans < 0) return 0;
        return ans;
    }
};