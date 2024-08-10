// leetcode
// https://leetcode.com/problems/binary-tree-paths/

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

    void findPath(TreeNode* root, string path, vector<string>& ans){
        if(root == NULL) return ;
            
        path += to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }
        path += "->";
        findPath(root->left, path , ans);
        findPath(root->right, path, ans);        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        findPath(root, path, ans);
        return ans;
    }
};