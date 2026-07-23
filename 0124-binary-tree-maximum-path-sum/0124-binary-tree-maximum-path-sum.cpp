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
    int maxSum;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int final_ans = left + right + root->val;
        int either = max(left, right) + root->val;
        int only_root = root->val;

        maxSum = max({maxSum, final_ans, either, only_root});

        return max(either, only_root);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;    
    }
};