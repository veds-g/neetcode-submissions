class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0, fresh = 0, rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;

        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (fresh > 0 and !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i][0];
                    int c = col + dir[i][1];

                    if (r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] != 1) {
                        continue;
                    }

                    grid[r][c] = 2;
                    q.push({r, c});
                    fresh--;
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
