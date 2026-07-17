class Solution {
public:
    bool makesquare(vector<int>& m) {
        int sum = accumulate(m.begin(), m.end(), 0);
        if (sum % 4 != 0) return false;
        
        int target = sum / 4;
        vector<int> sides(4, 0);
        sort(m.begin(), m.end());

        return solve(0, m, sides, target);
    }

    bool solve(int i, vector<int>& m, vector<int>& sides, int target) {
        if (i == m.size()) {
            return true;
        }

        for (int j = 0; j < 4; j++) {
            if (sides[j] + m[i] <= target) {
                sides[j] += m[i];
                if (solve(i + 1, m, sides, target)) return true;
                sides[j] -= m[i];
            }
            if (sides[j] == 0) break;
        }

        return false;
    }
};