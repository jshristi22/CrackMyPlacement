// leetcode
// https://leetcode.com/problems/same-tree/description/

// TC: O(N)
// SC: O(N)

class Solution {   
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr){
            return (p==q);
        }
        return (p->val == q->val) 
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
    }
};