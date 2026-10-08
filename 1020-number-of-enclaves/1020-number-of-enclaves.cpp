class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0 || visited[row][col]){
            return;
        }

        visited[row][col] = 1;

        dfs(grid, visited, row+1, col);
        dfs(grid, visited, row-1, col);
        dfs(grid, visited, row, col+1);
        dfs(grid, visited, row, col-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int row = 0; row < n; row++){
            if(grid[row][0] == 1){
                dfs(grid, visited, row, 0);
            }
            if(grid[row][m-1] == 1){
                dfs(grid, visited, row, m-1);
            }
        }

        for(int col = 0; col < m; col++){
            if(grid[0][col] == 1){
                dfs(grid, visited, 0, col);
            }
            if(grid[n-1][col] == 1){
                dfs(grid, visited, n-1, col);
            }
        }

        int count = 0; 
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};