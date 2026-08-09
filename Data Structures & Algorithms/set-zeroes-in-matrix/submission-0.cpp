class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        unordered_set<int> rows, cols;

        int r = m.size(), c = m[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (m[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (rows.contains(i) or cols.contains(j)) {
                    m[i][j] = 0;
                }
            }
        }
    }
};
