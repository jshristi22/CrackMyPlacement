// gfg
// https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

class Solution{
int largestRectangleArea(vector<int> &histo){
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for(int i = 0; i<=n; i++){
        while(!st.empty() &&
            (i == n || histo[st.top()] >= histo[i])
        ){
            int height = histo[st.top()];
            st.pop();
            int width;
            if(st.empty())
                width = i;
            else 
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}
public:
int maxArea(int matrix[MAX][MAX], int n, int m) {
    vector<int> histo(m, 0);
    int ans = 0;
    for(int i = 0 ; i<n; i++){
        for(int j = 0; j<m; j++){
            int ele = matrix[i][j];
            if( ele == 1)
                histo[j] += ele;
            else 
                histo[j] = 0;
        }
        int area = largestRectangleArea(histo);
        ans = max(ans, area);
    }
    return ans;
}
};