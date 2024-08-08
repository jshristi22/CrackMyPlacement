// leetcode
// https://leetcode.com/problems/symmetric-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    bool checkTree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr) return true;        

        if(root != nullptr && subRoot != nullptr && root->val == subRoot-> val)
            return checkTree(root->left, subRoot->right) 
                && checkTree(root->right, subRoot->left);   
                         
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return checkTree(root->left, root->right);
    }
};