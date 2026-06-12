class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long sq = (long)mid * mid;
            if (sq == x) return mid;
            else if (sq < x) l = mid + 1;
            else r = mid - 1;
        }

        return r;
    }
};