class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums, target, 0, 0, temp, res);
        return res;
    }

    void solve(vector<int>& nums, int target, int currSum, int idx, vector<int>& temp, vector<vector<int>>& res) {
        if (currSum == target) {
            res.push_back(temp);
            return;
        }
        if (idx == nums.size()) {
            return;
        }

        solve(nums, target, currSum, idx + 1, temp, res);

        if (currSum + nums[idx] <= target) {
            temp.push_back(nums[idx]);
            solve(nums, target, currSum + nums[idx], idx, temp, res);
            temp.pop_back();
        }
    }
};
