class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree){
        queue<int> q;
        vector<int> result;
        int count = 0;

        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                result.push_back(i);
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int  &it: adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    result.push_back(it);
                    q.push(it);
                    count++;
                }
            }
        }

        if(count == n){
            return result;
        }
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &vec:prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);

            indegree[a]++;
        }

        return topoSort(adj, numCourses, indegree);
    }
};