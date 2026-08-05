class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        
        int a = 1, b = 2;
        int curr;
        for(int i = 3; i <= n; i++) {
            curr = a + b;
            a = b;
            b = curr; 
        }
        return curr;
    }
};
