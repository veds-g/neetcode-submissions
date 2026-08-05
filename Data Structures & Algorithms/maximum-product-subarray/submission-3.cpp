class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], minP = nums[0], ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            if (x == 0) {
                maxP = 0; minP = 0;
            } else if (x > 0) {
                maxP = max(maxP * x, x);
                minP = min(minP * x, x);
            } else {
                int temp = maxP;
                maxP = max(minP * x, x);   // negative × negative = positive
                minP = min(temp * x, x);   // positive × negative = negative
            }
            ans = max(ans, maxP);
        }

        return ans;
    }
};
