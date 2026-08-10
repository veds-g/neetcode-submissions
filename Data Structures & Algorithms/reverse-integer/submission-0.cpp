class Solution {
public:
    int reverse(int x) {
        int sign = x < 0;

        int num = 0;
        x = abs(x);

        while (x) {
            int digit = x % 10;
            x /= 10;
            if (num > INT_MAX / 10 || num < INT_MIN / 10) return 0;
            num = num * 10 + digit;
        }

        return sign ? -num : num;
    }
};
