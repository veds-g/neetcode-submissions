class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;
        int l = 0, r = h.size() - 1;
        while (l < r) {
            int curr = min(h[l], h[r]) * (r - l);
            ans = max(ans, curr);

            if (h[l] < h[r]) l++;
            else r--;
        }

        return ans;
    }
};
