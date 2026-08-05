class Solution {
public:
    string stoneGameIII(vector<int>& s) {
        vector<string> ans = {"Alice", "Bob", "Tie"};

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int c1 = s[i] - (i + 1 < n ? dp[i + 1] : 0);
            int c2 = s[i] + (i + 1 < n ? s[i + 1] : 0) - (i + 2 < n ? dp[i + 2] : 0);
            int c3 = s[i] + (i + 1 < n ? s[i + 1] : 0) + (i + 2 < n ? s[i + 2] : 0) - (i + 3 < n ? dp[i + 3] : 0);
            dp[i] = max(c1, max(c2, c3));
        }

        return ans[dp[0] == 0 ? 2 : dp[0] > 0 ? 0 : 1];
    }
};