// leetcode
// https://leetcode.com/problems/invert-binary-tree/description/

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
    void reverse(TreeNode* root){
        if(root == nullptr) return;
        
        if(root->left != nullptr && root->right != nullptr){
            auto left = root->left;
            root->left = root->right;
            root->right = left;
        }
        else if(root->right != nullptr){
            root->left = root->right;
            root->right = nullptr;
        }else{
            root->right = root->left;
            root->left = nullptr;
        }

        reverse(root->left);
        reverse(root->right);    
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;                
        reverse(root);
        return root;
    }
};