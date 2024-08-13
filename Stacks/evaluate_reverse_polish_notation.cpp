// leetcode
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


class Solution {
private:
    bool isOperand(string val){
         return !(val == "+" || val == "-" || val == "*" || val == "/");
    }
    int getTotal(int a, int b, string sign){
        if(sign == "+") return a+b;
        if(sign == "-") return a-b;
        if(sign == "*") return a*b;
        return a/b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        int i = 0;
        stack<int> st;

        while(i < tokens.size()){
            if(isOperand(tokens[i])){
                st.push(stoi(tokens[i]));
            }else if(!st.empty()){
                int ele2 = st.top();
                st.pop();
                int ele1 = st.top();
                st.pop();
                int sum = getTotal(ele1, ele2, tokens[i]);
                // cout<<sum;
                st.push(sum);
            }
            i++;
        }
        return st.top();
    }
};