class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        solve(0, nums, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void solve(int idx, vector<int>& nums, set<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.insert(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx and  nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            solve(idx + 1, nums, ans);
            swap(nums[i], nums[idx]);
        }

        // for (int i = nums.size() - 1; i > idx; i--) {
        //     swap(nums[i], nums[idx]);
        // }
    }
};