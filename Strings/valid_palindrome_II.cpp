#include<bits/stdc++.h>
using namespace std;
// Solved it on leetcode
// https://leetcode.com/problems/valid-palindrome-ii/description/


class Solution {
private:
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0; int j = n -1;
        
        while( i < j){
            if(s[i] == s[j]){
                i++, j--;
            }
            else {                                
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);                            
            }            
        }
        return true;
    }
};