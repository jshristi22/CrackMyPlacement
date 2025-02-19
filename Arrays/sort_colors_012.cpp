import <bits/stdc++.h>
using namespace std;
// Solved on leetcode
// https://leetcode.com/problems/sort-colors/

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int m = 0;
    int r = n-1;
    while(m <= r){
        switch(nums[m]){
            case 0: 
                swap(nums[l++], nums[m++]);
                break;
            
            case 1:
                m++;
                break;

            case 2: 
                swap(nums[m], nums[r--]);
                break;
        }
    }
}