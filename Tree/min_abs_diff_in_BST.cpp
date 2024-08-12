// leetcode
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
    int getMinimumDifference(TreeNode* root) {
        // get inorder traversal
        // it'll be in ascending order, the diff of 1st 2 number is the answer
        if(root == NULL) return 0;
        stack<TreeNode* > myStack;
        vector<int> ans;
        while(true){
            if(root != NULL){
                myStack.push(root);
                root = root->left;                
            }else{
                if(myStack.empty()) break;
                auto node = myStack.top();
                myStack.pop();
                ans.push_back(node->val);
                root = node->right;
            }
        }
        int minVal = INT_MAX;
        for(int i = 0; i<ans.size()-1; i++){
            minVal = min(minVal, abs(ans[i] - ans[i+1]));
        }
        return minVal;
    }
};