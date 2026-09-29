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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> leftst;
        stack<TreeNode*> rightst;

        TreeNode* curr = root;
        
        while(curr != NULL){
            leftst.push(curr);
            curr = curr->left;
        }

        curr = root;

        while(curr != NULL){
            rightst.push(curr);
            curr = curr->right;
        }

        while(!leftst.empty() && !rightst.empty()){
            TreeNode* leftNode = leftst.top();
            TreeNode* rightNode = rightst.top();

            if(leftNode == rightNode) break;

            int sum = leftNode->val + rightNode->val;

            if(sum == k){
                return true;
            }
            if(sum < k){
                curr = leftst.top();
                leftst.pop();
                curr = curr->right;
                while(curr){
                    leftst.push(curr);
                    curr = curr->left;
                }
            }
            else{
                curr = rightst.top();
                rightst.pop();
                curr = curr->left;
                while(curr){
                    rightst.push(curr);
                    curr = curr->right;
                }
            }
        }
        return false;
    }
};