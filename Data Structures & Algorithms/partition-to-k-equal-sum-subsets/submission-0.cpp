class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        int subsetSum = sum / k;
        vector<int> sums(k, 0);
        sort(nums.rbegin(), nums.rend());

        return solve(0, nums, sums, subsetSum, k);
    }

    bool solve(int idx, vector<int>& nums, vector<int>& sums, int subsetSum, int k) {
        if (idx == nums.size()) {
            return true;
        }

        for (int i = 0; i < k; i++) {
            if (sums[i] + nums[idx] <= subsetSum) {
                sums[i] += nums[idx];
                if (solve(idx + 1, nums, sums, subsetSum, k)) return true;
                sums[i] -= nums[idx];
            }
            
            if (sums[i] == 0) break;
        }

        return false;
    }
};