class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int row = mat.size(), col = mat[0].size();

        int l = 0, r = row * col - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            int mr = m / col, mc = m % col;
            int val = mat[mr][mc];
            if (val == t) return true;
            else if (val < t) l = m + 1;
            else r = m - 1;
        }

        return false;
    }
};
