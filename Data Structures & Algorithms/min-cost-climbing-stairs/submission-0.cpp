#include <bits/stdc++.h>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++) {
            int currCost = i == n ? 0 : cost[i];
            int oneStepBack = i - 1 >= 0 ? dp[i - 1] : 0;
            int twoStepBack = i - 2 >= 0 ? dp[i - 2] : 0;
            dp[i] = currCost + min(oneStepBack, twoStepBack);
        }
        return dp[n];
    }
};
