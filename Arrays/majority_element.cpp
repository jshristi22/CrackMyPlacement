import <bits/stdc++.h>
using namespace std;
// Solved on leetcode
// https://leetcode.com/problems/majority-element/


int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int f = n/2;
        unordered_map<int, int> freq;

        for(auto it: nums){
           freq[it]++;
        }
        for(auto it:freq){
            if(it.second > f) 
                return it.first;
        }
        return 0;
    }