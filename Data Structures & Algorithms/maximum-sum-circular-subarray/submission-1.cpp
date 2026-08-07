class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // op1 - normal subarray
        int op1 = nums[0], sum1 = 0;
        for (auto& num : nums) {
            sum1 = max(sum1 + num, num);
            op1 = max(op1, sum1);
        }

        // op2 - rotated subarray
        int op2 = nums[0], sum2 = 0;
        for (auto& num : nums) {
            sum2 = min(sum2 + num, num);
            op2 = min(op2, sum2);
        }

        op2 = accumulate(nums.begin(), nums.end(), 0) - op2;

        return op1 > 0 ? max(op1, op2) : op1;
    }
};