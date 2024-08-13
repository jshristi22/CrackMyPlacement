// leetcode
// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {    
        // Min-heap to store the top k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push the elements into the heap & if size goes beyond k remove top element
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(i >= k){
                pq.pop();
            }
        }
        return pq.top();
    }
};  