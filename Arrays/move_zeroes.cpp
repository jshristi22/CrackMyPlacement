import <bits/stdc++.h>
using namespace std;
// Solved on leetcode
// https://leetcode.com/problems/move-zeroes/


void moveZeroes(vector<int>& nums) {      
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                nums[count] = nums[i];
                count++;
            }
        }
        for(int i = count; i<n; i++){
            nums[i] = 0;
        }
    }