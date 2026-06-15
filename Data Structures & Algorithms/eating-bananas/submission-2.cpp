class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int mx = *max_element(p.begin(), p.end());
        if (p.size() == h) return mx;

        int l = 1, r = mx, res = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long totalTime = 0;
            for (int x : p) {
                totalTime += ceil((double)x / mid);
            }
            if (totalTime > h) l = mid + 1;
            else res = mid, r = mid - 1;
        }
        return res;
    }
};