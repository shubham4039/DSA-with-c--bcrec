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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        ll maxWidth = 0;

        while(!q.empty()){
            ll left = q.front().second;
            ll right = q.back().second;

            maxWidth = max(maxWidth, right-left+1);

            ll n = q.size();
            while(n--){
                TreeNode* current = q.front().first;
                ll ind = q.front().second;
                q.pop();

                if(current->left){
                    q.push({current->left, 2*ind + 1});
                }
                if(current->right){
                    q.push({current->right, 2*ind + 2});
                }
            }
        }
        return maxWidth;
    }
};