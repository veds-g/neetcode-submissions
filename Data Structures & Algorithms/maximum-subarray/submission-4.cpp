class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, mx = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            curr = max(curr + nums[i], nums[i]);
            mx = max(mx, curr);
        }

        return mx;
    }
};
