class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        int rows = m.size(), cols = m[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans[j][i] = m[i][j];
            }
        }

        return ans;
    }
};