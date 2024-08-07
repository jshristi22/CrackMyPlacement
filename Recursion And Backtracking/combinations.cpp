
// leetcode
// https://leetcode.com/problems/combinations/

class Solution {
private:
    void find(int ind, vector<int>& arr, vector<int>& dp, vector<vector<int>>& ans, int k){
        // base case
        if(dp.size() == k){
            ans.push_back(dp);
            return;
        }

        for(int i = ind; i < arr.size(); i++){ // O(2^N)
            dp.push_back(arr[i]);
            find(i + 1, arr, dp, ans, k);
            dp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for(int i = 0; i<n; i++) arr.push_back(i+1);  //O(N)
        vector<vector<int>> ans;
        vector<int> dp;
        find(0, arr, dp, ans, k);
        return ans;
    }
};