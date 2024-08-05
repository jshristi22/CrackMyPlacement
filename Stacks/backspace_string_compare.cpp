// leetcode
// https://leetcode.com/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(string s, string t) {        
        int n = s.size();
        int m = t.size();
        stack<char> s1, s2;
        int i, j;
        i = j = 0;
        while( i < n){
            if(s[i] != '#'){
                s1.push(s[i]);                
            }else if(!s1.empty()){
                s1.pop();
            }
            i++;
        }        
        while( j < m){
            if(t[j] != '#'){
                s2.push(t[j]);                
            }else if(!s2.empty()){
                s2.pop();
            }
            j++;
        }
        if(s1.size() != s2.size()) return false;
       
        while(!s1.empty()){
            char ele1 = s1.top();
            char ele2 = s2.top();
            s1.pop();
            s2.pop();            
            if(ele1 != ele2) return false;
        }
        
        return true;
    }
};