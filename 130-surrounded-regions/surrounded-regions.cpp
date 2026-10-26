class Solution {
public:
    void bfs(int sr, int sc, vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        board[sr][sc] = '#';  // Temporarily mark as safe

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    board[nr][nc] == 'O') {

                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<char>> solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return board;

        int rows = board.size();
        int cols = board[0].size();

        // Process left and right boundaries
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O')
                bfs(i, 0, board);

            if (board[i][cols - 1] == 'O')
                bfs(i, cols - 1, board);
        }

        // Process top and bottom boundaries
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O')
                bfs(0, j, board);

            if (board[rows - 1][j] == 'O')
                bfs(rows - 1, j, board);
        }

        // Capture surrounded regions and restore safe cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }

        return board;
    }
};