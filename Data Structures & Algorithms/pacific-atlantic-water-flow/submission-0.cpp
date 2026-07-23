class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, int>> pacific, atlantic;
        int rows = heights.size(), cols = heights[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (i == 0 || j == 0) pacific.push({i, j});
                if (i == rows - 1 || j == cols - 1) atlantic.push({i, j});
            }
        }

        vector<vector<int>> final1(rows, vector<int>(cols, 0));
        vector<vector<int>> final2(rows, vector<int>(cols, 0));

        int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

        while(!pacific.empty()) {
            pair<int, int> p = pacific.front();
            pacific.pop();
            int row = p.first, col = p.second;
            final1[row][col] = 1;
            
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0], c = col + dir[i][1];
                if (r < 0 or r >= rows or c < 0 or c >= cols or heights[r][c] < heights[row][col] or final1[r][c] == 1) {
                    continue;
                }
                pacific.push({r, c});
            }
        }

        while(!atlantic.empty()) {
            pair<int, int> p = atlantic.front();
            atlantic.pop();
            int row = p.first, col = p.second;
            final2[row][col] = 1;
            
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0], c = col + dir[i][1];
                if (r < 0 or r >= rows or c < 0 or c >= cols or heights[r][c] < heights[row][col] or final2[r][c] == 1) {
                    continue;
                }
                atlantic.push({r, c});
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(final1[i][j] == 1 and final2[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
