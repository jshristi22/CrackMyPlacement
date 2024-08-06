// leetcode
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/


// TC: O(n)
// SC: O(n)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
    }
};