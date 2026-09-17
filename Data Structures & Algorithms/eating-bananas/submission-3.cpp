class Solution {
private:
    bool canEat(int m, vector<int>& piles, int h) {
        int cnt = 0;
        for (auto& x : piles) {
            int times = ceil(x * 1.0 / m);
            cnt += times;
        }
        return cnt <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == h) return *max_element(piles.begin(), piles.end());

        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (canEat(m, piles, h)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};
