class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, sum = 0, ans = INT_MAX;

        while (r < n) {
            sum += nums[r];

            if (sum >= target) {
                while(l <= r && sum >= target) {
                    ans = min(ans, r - l + 1);
                    sum -= nums[l++];
                }
            }

            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};