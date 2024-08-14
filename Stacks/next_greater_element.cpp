// leetcode
// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        // ele: nge
        unordered_map<int, int> mpp;
        for(int i = n - 1; i >= 0;  i--){
            if(st.empty()){
                mpp[nums2[i]] = -1;
                st.push(nums2[i]);
            }else{
                if(st.top() > nums2[i]){
                    mpp[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }else{
                    while(!st.empty() && st.top() <= nums2[i]){
                        st.pop();
                    }
                    if(st.empty()) mpp[nums2[i]] = -1;
                    else mpp[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
            }
        }
        vector<int> result;
        for(auto it: nums1){
            result.push_back(mpp[it]);
        }
        return result;
    }
};