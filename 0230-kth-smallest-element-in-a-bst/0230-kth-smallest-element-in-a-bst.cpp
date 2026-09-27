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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int ans = -1;

        while(curr != NULL){
            if(curr->left == NULL){
                k--;
                if(k == 0){
                    ans = curr->val;
                }
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
                    k--;
                    if(k==0){
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        } 
        return ans;
    }
};