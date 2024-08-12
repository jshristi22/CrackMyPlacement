// leetcode
// https://leetcode.com/problems/sum-of-left-leaves/description/

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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it->right != NULL){
                q.push(it->right);
            }
            
            if(it->left != NULL){
                if(it->left->left == NULL && it->left->right == NULL){ // leaf node
                    sum += it->left->val;
                }else q.push(it->left);
            }
        }
        return sum;
    }
};