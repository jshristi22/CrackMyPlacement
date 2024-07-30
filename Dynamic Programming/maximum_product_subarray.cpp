// leetcode
// https://leetcode.com/problems/maximum-product-subarray/description/
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    double ans = INT_MIN;
    double prefix = 1;
    double suffix = 1;
    for(int i = 0; i<n; i++){
        if(prefix == 0){
            prefix = 1;
        }
        if(suffix == 0){
            suffix= 1;
        }
        prefix = prefix * nums[i];
        suffix = suffix * nums[n-i-1];
        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}