class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
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
        
        for (int i = idx; i < nums.size(); i++) {
            if (currSum + nums[idx] > target) {
                return;
            }
            temp.push_back(nums[i]);
            solve(nums, target, currSum + nums[i], i, temp, res);
            temp.pop_back();
        }
    }
};
