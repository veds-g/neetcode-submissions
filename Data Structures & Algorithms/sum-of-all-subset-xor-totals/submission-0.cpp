class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        calc(nums, 0, 0, ans);
        return ans;
    }

    void calc(vector<int>& nums, int i, int currXOR, int& ans) {
        if (i == nums.size()) return;

        // 2 choices
        // Skip current
        calc(nums, i + 1, currXOR, ans);

        // XOR with curr
        currXOR ^= nums[i];
        ans += currXOR;
        calc(nums, i + 1, currXOR, ans);
    }
};