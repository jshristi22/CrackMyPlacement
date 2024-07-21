#include <bits/stdc++.h> 

using std namespace;

// Solved on leetcode
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

int strStr(string haystack, string needle) {        
        for(int i = 0; i<haystack.size() ; i++){
            int idx = i;
            for( int k = 0;  k < needle.size(); k++){
                int str = haystack[idx];
                if(str == needle[k]){
                    idx++;
                }else k = needle.size();
                if(k == needle.size() - 1) return i;
            }
        }
        return -1;
    }