import <bits/stdc++.h>
using namespace std;
// Solved on leetcode
// https://leetcode.com/problems/find-the-duplicate-number/


 int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        // Time limit exceeding;
        // for(int i = 0; i<n; i++){
        //     int currentEle = nums[i];
        //     for(int j = i+1; j<n; j++){
        //         if(currentEle == nums[j]){
        //             return currentEle;                    
        //         }
        //     }
        // }
        // return -1;

        // Linear time complexity using hash map logic
        for(int i = 0; i<n; i++){
            int idx = arr[i] % n;
            arr[idx] += n;
        }

        for(int i = 0; i<n; i++){
            if((arr[i]/n) >= 2){
                return i;
            }
        }
        return -1;
    }