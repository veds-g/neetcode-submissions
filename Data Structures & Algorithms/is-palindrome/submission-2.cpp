class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1) return true;

        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && (!(s[l] >= 'a' && s[l] <= 'z') && !(s[l] >= '0' && s[l] <= '9'))) l++;
            while (l < r && (!(s[r] >= 'a' && s[r] <= 'z') && !(s[r] >= '0' && s[r] <= '9'))) r--;
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
