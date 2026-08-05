class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int ans = INT_MIN;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i++) {
            int temp = max(a + nums[i], b);
            a = b;
            b = temp;
        }
        ans = max(ans, b);

        a = 0, b = 0;
        for (int i = 1; i < n; i++) {
            int temp = max(a + nums[i], b);
            a = b;
            b = temp;
        }
        ans = max(ans, b);

        return ans;
    }
};
