class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        int l = 0, r = 0;
        while (r < p.size()) {
            if (r > l) {
                if (p[r] - p[l] > 0) {
                    ans += p[r] - p[l];
                }
                l = r;
            }
            r++;
        }
        return ans;
    }
};