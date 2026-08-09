class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while (true) {
            int sum = 0;
            s.insert(n);
            while (n) {
                int temp = n % 10;
                sum += pow(temp, 2);
                n /= 10;
            }
            if (sum == 1) return true;
            else if (s.contains(sum)) return false;
            n = sum;
        }
    }
};
