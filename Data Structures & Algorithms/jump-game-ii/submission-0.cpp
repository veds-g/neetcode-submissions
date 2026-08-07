class Solution {
public:
    int jump(vector<int>& nums) {
        int idx = 0, steps = nums[0], n = nums.size(), cnt = 0;
        while (idx < n - 1) {
            int next = -1, maxDist = -1;
            for (int i = 1; i <= steps; i++) {
                if (idx + i >= n - 1) return cnt + 1;
                if ((nums[idx + i] + i + idx) >= maxDist) {
                    maxDist = nums[idx + i] + i + idx;
                    next = idx + i;
                }
            }

            if (next == -1) {
                return -1;
            }

            idx = next;
            steps = nums[next];
            cnt++;
        }

        return idx >= (n - 1) ? cnt : -1;
    }
};
