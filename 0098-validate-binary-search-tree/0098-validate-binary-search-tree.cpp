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
    bool isValidBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        bool ans = true;

        while(curr != NULL){
            if(curr->left == NULL){
                if(prev != NULL && prev->val >= curr->val){
                    ans = false;
                }
                prev = curr;
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    pred->right = NULL;

                    if(prev != NULL && prev->val >= curr->val){
                        ans = false;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};