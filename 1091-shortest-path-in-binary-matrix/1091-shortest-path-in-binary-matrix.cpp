class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>>> pq;

        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        
        dist[0][0] = 1;
        pq.push({1, 0, 0});

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!pq.empty()){
            auto [d, x, y] = pq.top();

            pq.pop();

            if(d > dist[x][y]) continue;
            if(x == n-1 && y == n-1) return d;

            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny]==0){
                   int newDist = d + 1;
                   if(newDist < dist[nx][ny]){
                    dist[nx][ny] = newDist;
                    pq.push({newDist, nx, ny});
                   }
                }
            }
        }
        return -1;
    }
};