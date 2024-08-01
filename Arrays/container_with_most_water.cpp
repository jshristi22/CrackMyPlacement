// leetcode
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        // O(N) using 2 pointers
        int ans = 0;
        int n = height.size();
        int l = 0, r = n-1;

        while(l<r){
            int h = min(height[l] , height[r]);
            int w = r - l;
            int water = h * w;
            ans = max(water, ans);
            if(height[l] <= height[r]) l++;
            else r--;
        }
        return ans;

// O(N^2)
        // for(int i= 0; i<n; i++){            
        //     for(int j = i+1; j<n; j++){
        //         int h = min(height[i] , height[j]);
        //         int w = j - i;
        //         int water = h * w;
        //         ans = max(water, ans);
        //     }
        // }
        // return ans;
    }
};