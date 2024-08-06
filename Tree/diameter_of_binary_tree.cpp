
// leetcode
// https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
    private:
    int heightBT(TreeNode* root, int& maxi){
        if(root == nullptr) return 0;

        int lh = heightBT(root->left, maxi);
        int rh = heightBT(root->right, maxi);

        maxi = max(maxi, (lh+rh));
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        heightBT(root, maxi);
        return maxi;
    }
};