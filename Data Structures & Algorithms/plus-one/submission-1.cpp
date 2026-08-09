class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int sum = 1, carry = 0;
        for (auto& x : digits) {
            sum += x + carry;
            if (sum >= 10) carry = 1, sum -= 10;
            else carry = 0;

            x = sum;
            sum = 0;
        }

        if (carry) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
