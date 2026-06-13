class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r = m.size(), c = m[0].size(), cnt = r * c;

        int left = 0, right = cnt - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r1 = mid / c, c1 = mid % c;

            if (m[r1][c1] == t) return true;
            else if (m[r1][c1] < t) left = mid + 1;
            else right = mid - 1; 
        }

        return false;
    }
};
