class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0, steps = nums[0], n = nums.size();
        while (idx < n - 1) {
            int next = -1, maxDist = -1;
            for (int i = 1; i <= steps; i++) {
                if (idx + i >= n - 1) return true;
                if ((nums[idx + i] + i + idx) >= maxDist) {
                    maxDist = nums[idx + i] + i + idx;
                    next = idx + i;
                }
            }

            if (next == -1) {
                return false;
            }

            idx = next;
            steps = nums[next];
        }

        return idx >= (n - 1);
    }
};
