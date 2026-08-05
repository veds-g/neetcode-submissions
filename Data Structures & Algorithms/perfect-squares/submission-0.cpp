class Solution {
public:
    int numSquares(int num) {
        int n = sqrt(num);
        
        vector<int> sq;
        for(int i = 1; i <= n; i++) {
            sq.push_back(i * i);
        }

        vector<int> dp(num + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= num; i++) {
            for (auto& s : sq) {
                if (s > i) break;
                dp[i] = min(dp[i], 1 + dp[i - s]);
            }
        }

        return dp[num];
    }
};