// leetcode
// https://leetcode.com/problems/range-sum-of-bst/description/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        stack<TreeNode*> st;
        while(true){
            if(root != NULL){
                st.push(root);               
                root = root->left;
            }else{
                if(st.empty()) break;
                root = st.top();
                st.pop();
                if(root->val >= low && root->val <= high){
                    sum += root->val;
                }
                root = root->right;
            }
        }
        return sum;
    }
};