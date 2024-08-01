
// leetcode
// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        int sum = 0;
        // O(N)
        for(int i = 0; i<n; i++){
            sum += nums[i];         //prefix sum
            int remain = sum - k;       // remainder                       
            if(m.find(remain) != m.end()){
                cnt += m[remain];
            }
            m[sum ]++;
        }
        return cnt;

// O(N^2)
        // for(int i = 0; i<n; i++){
        //     int sum = 0;
        //     for(int j = i; j<n; j++){
        //         sum+= nums[j];
        //         if(sum == k) cnt++;
        //     }
        // }
        // return cnt;
    }

};  