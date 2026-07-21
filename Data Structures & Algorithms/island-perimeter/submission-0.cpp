class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return perimeter(grid, i, j);
                }
            }
        }
    }

    int perimeter(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 1;
        }

        if (grid[r][c] == -1) {
            return 0;
        }

        grid[r][c] = -1;

        int ans = 0;
        // Left
        ans += perimeter(grid, r, c - 1);
        // Top
        ans += perimeter(grid, r - 1, c);
        // Right
        ans += perimeter(grid, r, c + 1);
        // Down
        ans += perimeter(grid, r + 1, c);
        
        return ans;
    }
};