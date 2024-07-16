import <bits/stdc++.h>
using namespace std;
// Solved on leetcode
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

int removeDuplicates(vector<int>& nums) {
    set<int> ans;
    for(auto& it: nums){
        ans.insert(it);
    }
    int i = 0;
    for(auto& it: ans){
        nums[i] = it;
        i++;
    }
    return ans.size();
}