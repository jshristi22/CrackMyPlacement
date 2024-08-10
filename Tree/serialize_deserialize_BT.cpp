// leetcode
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        string s = "";
        queue<TreeNode* >q;
        q.push(root);
        
        while(!q.empty()){                                    
            auto it = q.front();
            q.pop();
            if(it == NULL){
                s.append("#,");
            }
            else s.append(to_string(it->val)+',');
            if(it != NULL){
                q.push(it->left);
                q.push(it->right);
            }                        
        }
        return s;
    };

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));