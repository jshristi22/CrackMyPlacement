// Solved on gfg
// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
       vector<long long int> ans(n, 1);
       long long int total = 1;
       int zero_count = 0;
       
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                total *= nums[i];
            } else {
                zero_count++;
            }
        }
    
        for (int i = 0; i < n; i++) {
            if (zero_count > 1) {
                ans[i] = 0;
            } else if (zero_count == 1) {
                if (nums[i] == 0) {
                    ans[i] = total;
                } else {
                    ans[i] = 0;
                }
            } else {
                ans[i] = total / nums[i];
            }
        }
        
        return ans;
    }
};