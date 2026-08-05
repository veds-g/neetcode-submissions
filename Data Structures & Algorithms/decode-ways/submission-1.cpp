class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int ways = 0;
            
            string one = {s[i-1]};
            if (one != "0") dp[i] += dp[i-1];

            if (i == 1) continue;
            
            string two = {s[i-2], s[i-1]};
            int val = stoi(two);
            if (val >= 10 && val <= 26) dp[i] += dp[i-2];
        }

        return dp[n];
    }
};
