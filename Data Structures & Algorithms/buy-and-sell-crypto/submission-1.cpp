class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, prev = -1;
        for (auto& x : prices) {
            if (prev == -1 || prev > x) {
                prev = x;
            } else {
                ans = max(ans, x - prev);
            }
        }
        return ans;   
    }
};
