class Solution {
   public:
    void bfs(int i, int j, vector<vector<int>> &grid,
             vector<vector<int>> &visited) {
        visited[i][j] = 1;

        queue<pair<int, int>> q;

        q.push({i, j});

        int row = grid.size();
        int col = grid[0].size();

        int dr[] = {-1, 1, 0, 0};
        int cr[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();

            int n = cell.first;
            int m = cell.second;

            for (int i = 0; i < 4; i++) {
                int nr = n + dr[i];
                int nc = m + cr[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 1 && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int count = 0;

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 1 && !visited[0][j]) bfs(0, j, grid, visited);

            if (grid[row - 1][j] == 1 && !visited[row - 1][j])
                bfs(row - 1, j, grid, visited);
        }

        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) bfs(i, 0, grid, visited);

            if (grid[i][col - 1] == 1 && !visited[i][col - 1])
                bfs(i, col - 1, grid, visited);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) count++;
            }
        }

        return count;
    }
};
