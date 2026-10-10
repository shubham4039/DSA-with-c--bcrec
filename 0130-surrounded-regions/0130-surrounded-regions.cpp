class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j){
        int m = board.size();
        int n = board[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' || visited[i][j]){
            return;
        }

        visited[i][j] = 1;

        dfs(board, visited, i + 1, j);
        dfs(board, visited, i - 1, j);
        dfs(board, visited, i, j + 1);
        dfs(board, visited, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(board[i][0] == 'O'){
                dfs(board, visited, i, 0);
            }
            if(board[i][n-1] == 'O'){
                dfs(board, visited, i, n-1);
            }
        }

        for(int j=0; j<n; j++){
            if(board[0][j] == 'O'){
                dfs(board, visited, 0, j);
            }
            if(board[m-1][j] == 'O'){
                dfs(board, visited, m-1, j);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};