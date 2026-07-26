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
    int findLeftHei(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHei(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftHei = findLeftHei(root);
        int rightHei = findRightHei(root);

        if(leftHei == rightHei) return (1<<leftHei) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};