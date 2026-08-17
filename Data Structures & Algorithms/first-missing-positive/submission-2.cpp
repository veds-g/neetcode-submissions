class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (auto& x : nums) if (x < 0 || x > n) x = 0;

        for (auto& x : nums) {
            if (x == 0 || abs(x) > n) continue;

            int idx = abs(x) - 1;
            if (nums[idx] < 0) continue;
            else if (nums[idx] > 0) nums[idx] *= -1;
            else nums[idx] = -(n + 1);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) return i + 1;
        }
        
        return n + 1;
    }
};