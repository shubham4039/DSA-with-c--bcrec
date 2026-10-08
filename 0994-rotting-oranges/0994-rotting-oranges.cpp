class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int freshCount = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0;

        int time = 0;
        int dirX[] = {-1, 1, 0, 0};
        int dirY[] = {0, 0, 1, -1};

        while(!q.empty()){
            int N = q.size();

            while(N--){
                pair<int, int> curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for(int d=0; d<4; d++){
                    int newi = i + dirX[d];
                    int newj = j + dirY[d];

                    if(newi >= 0 && newj >= 0 && newi < n && newj < m && grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        q.push({newi, newj});
                        freshCount--;
                    }
                }
            }
            time++;
        }

        return freshCount == 0 ? (time - 1) : -1;
    }
};