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
    int searchIdx(vector<int>& inorder, int left, int right, int val){
        for(int i = left; i <= right; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& posIdx, int left, int right){
        if(left > right){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[posIdx]);

        int inIdx = searchIdx(inorder, left, right, postorder[posIdx]);
        posIdx--;

        root->right = solve(inorder, postorder, posIdx, inIdx+1, right);
        root->left = solve(inorder, postorder, posIdx, left, inIdx-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posIdx = postorder.size()-1;
        return solve(inorder, postorder, posIdx, 0, inorder.size() - 1);
    }
};