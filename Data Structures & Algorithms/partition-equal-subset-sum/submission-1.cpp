class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) return false;

        int n = nums.size();
        
        bool dp[n + 1][total / 2 + 1];
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 0; i <= total / 2; i++) dp[0][i] = false;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= total / 2; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] |= dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][total / 2];
    }
};
