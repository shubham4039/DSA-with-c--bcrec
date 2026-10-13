class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<vector<int>> adj(v);

        queue<int> q;
        vector<int> indegree(v, 0);

        for(int i = 0; i<v; i++){
            for(auto &it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        for(int i = 0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<bool> isSafe(v, false);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            isSafe[node] = true;

            for(auto &it: adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i<v; i++){
            if(isSafe[i] == true){
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};