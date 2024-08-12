// leetcode
// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        for(int i = 2; i<=n; i++){
            int count = 0;
            while (i > 0) {
                if(i % 2 != 0)
                    count++;
                i /= 2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};