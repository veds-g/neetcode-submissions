class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0;
        int l = 0, r = 1, n = a.size();

        while (r < n) {
            while (r < n && a[r] > a[l]) {
                ans = max(ans, a[r] - a[l]);
                r++;
            }
            l = r;
            r++;
        }
        return ans;
    }
};
