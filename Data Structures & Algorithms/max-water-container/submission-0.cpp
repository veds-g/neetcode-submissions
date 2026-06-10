class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int ans = INT_MIN;
        while (l < r) {
            int mn = min(h[l], h[r]);
            ans = max(ans, mn * (r - l));
            h[l] < h[r] ? l++ : r--; 
        }
        return ans;
    }
};
