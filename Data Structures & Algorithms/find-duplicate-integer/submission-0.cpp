class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int mask = 0;

        for (int i = 0; i < nums.size(); i++) {
            int shifted = 1 << nums[i];

            if ((mask & shifted) != 0) return nums[i];
            mask |= shifted;
        }
    }
};
