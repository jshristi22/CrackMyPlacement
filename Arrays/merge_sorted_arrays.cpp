import <bits/stdc++.h>
using namespace std;
// Solved on leetcode
// https://leetcode.com/problems/merge-sorted-array/


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> mer;
    int i = 0, j = 0;
    while( i < m && j < n){
        if(nums1[i] <= nums2[j]){
            mer.push_back(nums1[i]);
            i++;
        }else{
            mer.push_back(nums2[j]);
            j++;
        }
    }
    while(i < m){
        mer.push_back(nums1[i]);
        i++;
    }
    while(j < n){
        mer.push_back(nums2[j]);
        j++;
    }
        for (int k = 0; k < mer.size(); k++) {
        nums1[k] = mer[k];
    }
}