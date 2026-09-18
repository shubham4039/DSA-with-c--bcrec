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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
        if(left > right){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int inIdx = mp[preorder[preIdx]];
        preIdx++;

        root->left = solve(preorder, inorder, preIdx, left, inIdx-1);
        root->right = solve(preorder, inorder, preIdx, inIdx+1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int preIdx = 0;
        return solve(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};