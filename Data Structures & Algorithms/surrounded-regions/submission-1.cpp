class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 or j == 0 or i == rows -1 or j == cols - 1) {   
                    if (board[i][j] == 'O') {
                        q.push({i, j});
                    }
                }
            }
        }

        int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

        while(q.size()) {
            pair<int, int> p = q.front();
            q.pop();
            int row = p.first, col = p.second;
            board[row][col] = '#';

            for (int i = 0; i < 4; i++) {
                int r = row + dir[i][0], c = col + dir[i][1];
                if (r < 0 or c < 0 or r >= rows or c >= cols) continue;
                if (board[r][c] == 'O') q.push({r, c});
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

