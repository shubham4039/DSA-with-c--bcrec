class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> result(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            for(int d=0; d<4; d++){
                int new_i = i + dx[d];
                int new_j = j + dy[d];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && result[new_i][new_j]==-1){
                    result[new_i][new_j] = result[i][j] + 1;
                    q.push({new_i, new_j});
                }
            }
        }
        return result;
    }
};