// gfg
// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution{
private:
    bool isOperand(char val){
        return val >= '0' && val <= '9';
    }
    int getTotal( int a, int b, char sign){
        if(sign == '+')  return a+b;
        if(sign == '-')  return a-b;
        if(sign == '*')  return a*b;
        if(sign == '/')  return a/b;
    }
    
    bool isOperator(char val){
        return val == '+' || val == '-' || val =='*' || val == '/';
    }
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        int i = 0;
        stack<int> st;
        
        while(i<S.size()){
            if(isOperand(S[i])){
                st.push(S[i] - '0');
            }else if(isOperator(S[i]) && !st.empty()){
                int ele2 = st.top();
                st.pop();
                int ele1 = st.top();
                st.pop();
                
                int sum = getTotal(ele1, ele2, S[i]);
                st.push(sum);
            }
            i++;
        }
        return st.top();
    }
}