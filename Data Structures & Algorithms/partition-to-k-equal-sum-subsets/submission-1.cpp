class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        int subsetSum = sum / k;
        vector<int> vis(nums.size(), 0);
        sort(nums.rbegin(), nums.rend());

        return solve(0, k, 0, subsetSum, vis, nums);
    }

    bool solve(int idx, int k, int currSum, int target, vector<int>& vis, vector<int>& nums) {
        if (k == 0) {
            return true;
        }

        if (currSum == target) {
            return solve(0, k - 1, 0, target, vis, nums);
        }

        for (int i = idx; i < nums.size(); i++) {
            if (vis[i] or currSum + nums[i] > target) {
                continue;
            }

            vis[i] = 1;
            if (solve(idx + 1, k, currSum + nums[i], target, vis, nums)) {
                return true;
            }
            vis[i] = 0;
        }

        return false;
    }
};