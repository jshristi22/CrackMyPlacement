import <bits/stdc++.h>
using namespace std;
// Solved on leetcode
// https://leetcode.com/problems/two-sum/


 vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end()){
                ans.push_back(mp.at(target - nums[i]));
                ans.push_back(i);
                return ans;
            }else{
                mp.insert({nums[i],i});
            }
        }

        return ans;
    }