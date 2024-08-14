
// gfg
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution{
     private:
    int findCelebBruteForce(vector<vector<int> >& mat){
        int n = mat.size();
        int iKnow[n] = {0};
        int knowsMe[n] = {0};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 1){
                    iKnow[i] += 1;
                    knowsMe[j] += 1;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            if(iKnow[i] == 0 && knowsMe[i] == n-1) return i;
        }
        return -1;
    }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // return findCelebBruteForce(mat);
        
        int n= mat.size();
        int top = 0, last = n-1;
        while(top < last){
            if(mat[top][last]) top++;
            else if(mat[last][top]) last--;
            else{
                top++;
                last--;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(mat[last][i] == 1) return -1;
        }
        for(int j = 0; j<n; j++){
            if(last == j) continue;
            if(mat[j][last] == 0) return -1;
        }
        return last;
    }
}