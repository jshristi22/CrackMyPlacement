#include <bits/stdc++.h> 

using std namespace;

// Solved on leetcode
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int cnt = 0;
        for(int i = 1; i<strs.size(); i++){
            auto it = strs[i];
            for(int ptr = 0; ptr < it.size() && ptr<ans.size(); ptr++){
                if(it[ptr] == ans[ptr]){
                    cnt++;
                    cout<<it[ptr]<<" ";
                }else break;
            }
            if(cnt == 0) return "";
            else{
                // update ans
                string temp;
                for(int i = 0 ; i<cnt ; i++) {
                    temp += it[i];                    
                }
                ans = temp;
                cnt = 0;
            }
        }
        return ans;
    }
};