class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long remaining = n - 1;
        long long bit = 1;

        while(remaining) {
            if (!(ans & bit)) {
                if (remaining & 1) {
                    ans |= bit;
                }
                remaining >>= 1;
            }
            bit <<= 1;
        }

        return ans;
    } 
};