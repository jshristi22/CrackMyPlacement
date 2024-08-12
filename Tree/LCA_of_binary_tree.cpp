// leetcode
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* f(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == nullptr || node == p|| node == q) return node;
        
        auto left = f(node->left,p,q);
        auto right = f(node->right,p,q);
        
        if(left == nullptr) return right;
        else if(right == nullptr) return left;
        // if(left != nullptr && right != nullptr) 
        else return node;        
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        return f(root, p, q);
    }
};