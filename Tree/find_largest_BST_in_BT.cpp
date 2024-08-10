// GFG
// https://www.geeksforgeeks.org/problems/largest-bst/1

class NodeValue{
    public:
    int minNode, maxNode, maxSize;
    NodeValue(int mn, int mx, int size){
        this->minNode = mn;
        this->maxNode = mx;
        this->maxSize = size;
    }
};

class Solution{
    private:
    
    NodeValue findBst(Node *root){
        if(root == NULL)    {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        auto left = findBst(root->left);
        auto right = findBst(root->right);
        
        if(left.maxNode < root->data && root->data < right.minNode){
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 
            1 + left.maxSize + right.maxSize);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        return findBst(root).maxSize;
    	
    }
};