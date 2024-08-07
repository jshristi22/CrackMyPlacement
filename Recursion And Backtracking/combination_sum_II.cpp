// leetcode
// https://leetcode.com/problems/combination-sum-ii/

class Solution {
private:
    void findUnique(int ind, vector<int>&cand, int target, 
    vector<int>&ds,vector<vector<int>>&ans){
        // base case
        if(target == 0){
            ans.push_back(ds);            
            return;        
        }

        for(int i = ind; i<cand.size(); i++){
            if(i > ind && cand[i] == cand[i-1]) continue;
            
            if(cand[i] > target) break;            
            ds.push_back(cand[i]);
            findUnique(i+1, cand, target - cand[i], ds, ans);
            ds.pop_back();            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findUnique(0, candidates, target, ds, ans);
        return ans;        
    }
};