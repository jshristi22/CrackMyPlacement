
// leetcode
// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1339844261/

class Solution {
private:
     int lra(vector<int> &histo){
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
    int largestRectangleArea(vector<int>& heights) {
        return lra(heights);
    }
};