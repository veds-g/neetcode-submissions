class Solution {
private:
    double calc(double x, int n) {
        if (n == 0) return 1;
        double half = calc(x, n / 2);
        return n % 2 == 0 ? half * half : x * half * half;
    }
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        int divide = n < 0;
        
        double res = calc(x, abs(n));
        return divide ? 1 / res : res;
    }
};
