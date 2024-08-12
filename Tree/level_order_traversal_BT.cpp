// leetcode
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())    {
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i<size; i++){
                auto it = q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left != NULL) q.push(it->left);
                if(it->right != NULL) q.push(it->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};