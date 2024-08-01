// leetcode
// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int counts = 0;
        // for(int i = 0; i<n; i++){
        //     int sum = 0;
        //     for(int j = i; j<n; j++){
        //         sum += nums[j];
        //         if(sum % k == 0){
        //             counts++;
        //         }
        //     }
        // }
        // return counts;
        int prefix = 0;
        map<int,int> prefix_cnt;
        prefix_cnt[0] = 1;
        for(int i = 0; i<n; i++){
            prefix += nums[i];
            int remain = prefix % k;
            if(remain < 0) remain +=k;

            counts += prefix_cnt[remain];
            prefix_cnt[remain] += 1;
        }
        return counts;
    }
};