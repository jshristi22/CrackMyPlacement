
// leetcode
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // using O(1) space complexity
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            int ind = abs(nums[i]) - 1;
            if(nums[ind] < 0) {
                ans.push_back(ind + 1);
            }
            else nums[ind] *= -1;
        }
        return ans;



    // Using O(N) extra space
        unordered_map<int, int> m;
        // storing frequencies
        for(int i = 0; i<n; i++){
            m[nums[i]]++;
        }

        for(auto it: m){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        return ans;        
    }
};