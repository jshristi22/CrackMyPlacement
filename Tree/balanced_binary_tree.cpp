
// leetcode
// https://leetcode.com/problems/balanced-binary-tree/description/

// TC:O(N)
// SC:O(N)
class Solution {
    private:
    int heightBT(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = heightBT(root->left);
        int rh = heightBT(root->right);
        // if not balanced
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh - rh) > 1) return -1;
        return 1 + max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(heightBT(root) == -1) return false;
        return true;
    }
};