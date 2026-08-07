class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;   // can't reach here
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
