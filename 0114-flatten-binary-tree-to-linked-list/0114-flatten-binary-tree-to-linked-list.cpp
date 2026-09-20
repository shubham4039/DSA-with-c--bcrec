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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                curr = curr->right;
            }
            else{
                TreeNode* leftChild = curr->left;

                while(leftChild->right != NULL){
                    leftChild = leftChild->right;
                }
                leftChild->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
        } 
    }
};