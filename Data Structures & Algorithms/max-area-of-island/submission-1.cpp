class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
private:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        return 1 + 
        dfs(r + 1, c, grid) +
        dfs(r, c + 1, grid) + 
        dfs(r - 1, c, grid) + 
        dfs(r, c - 1, grid);
    }
};
