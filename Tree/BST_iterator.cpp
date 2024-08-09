// leetcode
// https://leetcode.com/problems/binary-search-tree-iterator/description/

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
class BSTIterator {
    private: stack<TreeNode*> myStack;
    private:
    void pushAll(TreeNode* root){
        while(root != NULL){
            myStack.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {    
        if(root != NULL)    
        pushAll(root);
    }
    
    int next() {
        if(hasNext()){
            TreeNode* node = myStack.top();
            myStack.pop();
            pushAll(node->right);
            return node->val;
        }
        return NULL;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */