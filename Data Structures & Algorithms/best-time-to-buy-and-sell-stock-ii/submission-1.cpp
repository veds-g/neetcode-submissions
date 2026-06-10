class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0, idx = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i == idx + 1) {
                if (p[i] > p[idx]) ans += p[i] - p[idx];
                idx = i;
            }
        }
        return ans;
    }
};