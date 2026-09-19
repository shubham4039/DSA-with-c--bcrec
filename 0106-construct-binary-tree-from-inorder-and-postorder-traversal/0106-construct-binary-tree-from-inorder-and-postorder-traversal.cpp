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
    unordered_map<int, int> mp;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& posIdx, int left, int right){
        if(left > right){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[posIdx]);

        int inIdx = mp[postorder[posIdx]];
        posIdx--;

        root->right = solve(inorder, postorder, posIdx, inIdx+1, right);
        root->left = solve(inorder, postorder, posIdx, left, inIdx-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int posIdx = postorder.size()-1;
        return solve(inorder, postorder, posIdx, 0, inorder.size() - 1);
    }
};