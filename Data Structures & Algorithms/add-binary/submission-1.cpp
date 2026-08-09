class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) swap(a, b);

        string newA = string(b.size() - a.size(), '0') + a;
        reverse(newA.begin(), newA.end());
        reverse(b.begin(), b.end());

        string ans = "";
        int sum = 0, carry = 0;
        for (int i = 0; i < b.size(); i++) {
            int first = newA[i] - '0';
            int second = b[i] - '0';
            sum += first + second + carry;
            
            if (sum < 2) {
                ans.push_back(sum + '0');
                sum = 0;
                carry = 0;
            } else {
                ans.push_back(sum == 2 ? '0' : '1');
                sum = 0;
                carry = 1;
            }
        }

        if (carry) ans.push_back('1');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};