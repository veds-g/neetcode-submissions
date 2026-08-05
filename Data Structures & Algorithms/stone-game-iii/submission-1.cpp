class Solution {
public:
    string stoneGameIII(vector<int>& s) {
        vector<string> ans = {"Alice", "Bob", "Tie"};

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            int total = 0;
            for (int j = i; j < min(i + 3, n); j++) {
                total += s[j];
                dp[i] = max(dp[i], total - dp[j + 1]);
            }
        }

        return ans[dp[0] == 0 ? 2 : dp[0] > 0 ? 0 : 1];
    }
};