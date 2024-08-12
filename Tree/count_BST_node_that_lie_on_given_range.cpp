// gfg
// https://www.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

class Solution{
public:
    int getCount(Node *root, int low, int high)
    {
        int sum = 0;
        stack<Node*> st;
        while(true){
            if(root != NULL){
                st.push(root);               
                root = root->left;
            }else{
                if(st.empty()) break;
                root = st.top();
                st.pop();
                if(root->data >= low && root->data <= high){
                    sum ++;
                }
                root = root->right;
            }
}
        return sum;
    }
};