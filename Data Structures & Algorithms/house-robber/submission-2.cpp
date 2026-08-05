class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int a = 0;
        int b = nums[0];

        for (int i = 1; i < n; i++) {
            int temp = max(a + nums[i], b);
            a = b;
            b = temp;
        }
        return b;
    }
};
