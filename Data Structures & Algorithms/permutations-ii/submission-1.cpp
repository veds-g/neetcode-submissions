class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }

    void solve(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx and  nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            solve(idx + 1, nums, ans);
            // swap(nums[i], nums[idx]);
        }

        for (int i = nums.size() - 1; i > idx; i--) {
            swap(nums[i], nums[idx]);
        }
    }
};