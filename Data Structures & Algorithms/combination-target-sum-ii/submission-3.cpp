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

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx and nums[i] == nums[i - 1]) continue;
            if (currSum + nums[i] > target) return;
            temp.push_back(nums[i]);
            solve(nums, target, currSum + nums[i], i + 1, temp, ans);
            temp.pop_back();
        }
    }
};
