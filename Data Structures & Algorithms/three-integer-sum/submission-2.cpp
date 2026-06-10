class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = 0 - nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int curr = nums[l] + nums[r];
                if (curr == target) {
                    vector<int> temp = {nums[i], nums[l], nums[r]};
                    if (find(res.begin(), res.end(), temp) == res.end()) res.push_back(temp);
                    l++;
                } else if (curr < target) l++;
                else r--;
            }
        }

        return res;
    }
};
