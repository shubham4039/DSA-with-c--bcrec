/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    
    void inorder(TreeNode* root){
        if(!root) return;

        if(root->left != NULL){
            parent[root->left] = root;
        }

        inorder(root->left);

        if(root->right != NULL){
            parent[root->right] = root;
        }

        inorder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>& result){
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);

        while(!q.empty()){
            int n = q.size();

            if(k==0){
                break;
            }

            while(n--){
                TreeNode* current = q.front();
                q.pop();

                if(current->left != NULL && !visited.count(current->left->val)){
                    q.push(current->left);
                    visited.insert(current->left->val);
                }

                if(current->right != NULL && !visited.count(current->right->val)){
                    q.push(current->right);
                    visited.insert(current->right->val);
                }

                if(parent.count(current) && !visited.count(parent[current]->val)){
                    q.push(parent[current]);
                    visited.insert(parent[current]->val);
                }
            }
            k--;
        }
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            result.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        inorder(root);

        BFS(target, k, result);

        return result;
    }
};