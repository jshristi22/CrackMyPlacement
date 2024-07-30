#include<bits/stdc++.h>
using namespace std;

// leetcode
// https://leetcode.com/problems/maximal-rectangle/

class Solution {
private:
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> histo(m, 0);
        int ans = 0;
        for(int i = 0 ; i<n; i++){
            for(int j = 0; j<m; j++){
                char ele = matrix[i][j] - '0' ;
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