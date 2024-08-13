
// leetcode
// https://leetcode.com/problems/ugly-number-ii/submissions/1354025431/


class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> vist;
        minHeap.push(1);
        vist.insert(1);
        vector<int> primes = {2,3,5};
        long ans = 1;
        for(int i = 1; i<=n; i++){
            ans = minHeap.top();
            minHeap.pop();

            for(auto it: primes){
                long nUgly = ans*it;
                if(vist.find(nUgly) == vist.end()){
                    minHeap.push(nUgly);
                    vist.insert(nUgly);
                }
            }
        }
        return (int)ans;
    }
};