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
    void makeGraph(unordered_map<int, vector<int>>& adj, int parent, TreeNode* curr){
        if(curr == NULL) return;

        if(parent != -1){
            adj[curr->val].push_back(parent);
        }
        if(curr->left){
            adj[curr->val].push_back(curr->left->val);
        }
        if(curr->right){
            adj[curr->val].push_back(curr->right->val);
        }
        makeGraph(adj, curr->val, curr->left);
        makeGraph(adj, curr->val, curr->right);
    }

    void dfs(unordered_map<int, vector<int>>& adj,
            int curr,
            unordered_set<int>& visited,
            int time,
            int& ans) {

        visited.insert(curr);

        ans = max(ans, time);

        for (int neighbour : adj[curr]) {
            if (visited.find(neighbour) == visited.end()) {
                dfs(adj, neighbour, visited, time + 1, ans);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);

        unordered_set<int> visited;
        int ans = 0;

        dfs(adj, start, visited, 0, ans);

        return ans;
    }
};