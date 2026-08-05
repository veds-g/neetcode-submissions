class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sz;
        sz.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > sz.back()) sz.push_back(nums[i]);
            else sz[(lower_bound(sz.begin(), sz.end(), nums[i])) - sz.begin()] = nums[i];
        }
        return sz.size();
    }
};
