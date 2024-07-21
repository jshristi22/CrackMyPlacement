#include <bits/stdc++.h> 

using std namespace;

// Solved on leetcode
// https://leetcode.com/problems/valid-parentheses/


bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(
            s[i] ==')' && st.top() == '(' ||
            s[i] =='}' && st.top() == '{' ||
            s[i] ==']' && st.top() == '['
        )
        st.pop();
        else {
            st.push(s[i]);
        }
    }
    return st.size() == 0;       
}

// [()]{}{[()()]()}