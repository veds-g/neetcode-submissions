class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            int val = mp[curr];

            if (i + 1 < s.size()) {
                char next = s[i + 1];
                if (curr == 'I' and (next == 'V' or next == 'X')) {
                    val *= -1;
                }
                if (curr == 'X' and (next == 'L' or next == 'C')) {
                    val *= -1;
                }
                if (curr == 'C' and (next == 'D' or next == 'M')) {
                    val *= -1;
                }
            }

            ans += val;
        }

        return ans;
    }
};