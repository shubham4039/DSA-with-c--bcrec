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
    void serHelper(TreeNode* root, string& s){
        if(root == nullptr){
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";

        serHelper(root->left, s);
        serHelper(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serHelper(root, s);
        return s;
    }

    TreeNode* deserHelper(stringstream& ss){
        string val;
        ss >> val;

        if(val == "#"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = deserHelper(ss);
        root->right = deserHelper(ss);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return deserHelper(ss);    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));