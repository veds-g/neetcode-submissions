class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        unordered_map<int, int> dp;
        dp[0] = 1;

        return maxCount(0, n, prefix, k, dp);
    }

    int maxCount(int i, int n, vector<int>& prefix, int k, unordered_map<int, int>& dp) {
        if (i == n) return 0;
        
        int need = prefix[i] - k;
        int matches = dp.contains(need) ? dp[need] : 0;

        dp[prefix[i]]++;

        return matches + maxCount(i + 1, n, prefix, k, dp);
    }
};