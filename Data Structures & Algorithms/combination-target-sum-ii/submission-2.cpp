class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, target, 0, 0, temp, ans);
        return ans;
    }

    void solve(vector<int>& nums, int target, int currSum, int idx, vector<int>& temp, vector<vector<int>>& ans) {
        if (currSum == target) {
            ans.push_back(temp);
            return;
        }

        if (currSum > target || idx == nums.size()) {
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, target, currSum + nums[idx], idx + 1, temp, ans);
        temp.pop_back();

        while (idx + 1 < nums.size() and nums[idx] == nums[idx + 1]) {
            idx++;
        }

        solve(nums, target, currSum, idx + 1, temp, ans);
    }
};
