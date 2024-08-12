// leetcode
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
        // Using recursion
        void iot(TreeNode* root,  vector<int> &ans){
            if(root == nullptr){
                return;
            }

            iot(root->left, ans);
            ans.push_back(root->val);
            iot(root->right, ans);
        }
public:
    vector<int> inorderTraversal(TreeNode* root) {        
        // iot(root, ans);
        // Using Morris traversal
        vector<int> inorder;
        while(root != nullptr){
            // if no left, put root in answer and move to right
            if(root->left == nullptr){
                inorder.push_back(root->val);
                root = root->right;
            }else{
                // if left present, find the rightmost guy in left subtree.
                auto prev = root->left;
                while(prev->right && prev->right != root){
                    prev = prev->right;                    
                }
                // if rightmost node is pointing to null, attach it to root, shift root to left
                if(prev->right == nullptr){
                    prev->right = root;
                    root = root->left;
                }else{
                // if not pointing to null, it states that this subtree has been visited,so
                // remove the connection between rightmost and root node, 
                // push node to ans
                // shift root to root->right
                    prev->right = nullptr;
                    inorder.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return inorder;

        // Using stack
        TreeNode* node = root;
        stack<TreeNode*> st;
        vector<int> ans;        
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};