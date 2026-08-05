class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int& coin : coins) {
                if (i < coin) break;
                if (dp[i - coin] == INT_MAX) continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
