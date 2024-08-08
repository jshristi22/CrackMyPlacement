// leetcode
// https://leetcode.com/problems/path-sum/submissions/1349203661/

class Solution {
private:   
     bool isSum(TreeNode* root, int target) {
        if (root == nullptr) return false;

        // If the current node is a leaf, check if the target equals the node's value
        if (root->left == nullptr && root->right == nullptr) {
            return target == root->val;
        }

        // Recursively check the left and right subtrees with the updated target sum        
        return isSum(root->left, target - root->val) || isSum(root->right, target - root->val);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) { 
        // if(root == nullptr) return false;          
        return isSum(root, targetSum);
    }
};