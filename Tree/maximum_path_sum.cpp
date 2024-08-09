// leetcode
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
    int maxPath(TreeNode* root, int& sum){
        if(root==nullptr) return 0;

        int lh = max(0, maxPath(root->left, sum));        
        int rh = max(0, maxPath(root->right, sum));

        sum = max(sum, (root->val + lh + rh));
        
        return root->val + max(lh, rh);
     
    }
public:
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        maxPath(root, max);
        return max;
    }
};