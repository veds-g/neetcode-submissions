class Solution {
public:
    string convertToTitle(int col) {
        string ans = "";

        while (col) {
            col--;
            int num = col % 26;
            ans += num + 'A';
            col /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};