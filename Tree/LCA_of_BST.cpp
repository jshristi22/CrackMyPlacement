// leetcode
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        TreeNode* ansNode;
        while(root != NULL){
            if(root->val < p->val && root->val < q->val && root->left != NULL){
                root = root->right;
            }
            else if(root->val > p->val && root->val > q->val && root->left != NULL){
                root = root->left;
            }
            else{
                ansNode = root;
                break;
            }
        }
        return ansNode;
    }
};