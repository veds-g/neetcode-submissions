class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums, 0, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void solve(vector<int>& nums, int idx, set<vector<int>>& ans) {
        if (idx == nums.size()) {
            return;
        }
        ans.insert(nums);

        for (int i = idx + 1; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            solve(nums, idx + 1, ans);
            swap(nums[i], nums[idx]);
        }

        solve(nums, idx + 1, ans);
    }
};
