class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int mx = INT_MIN, maxf = INT_MIN, l = 0, r = 0, n = s.size();

        while(r < n) {
            char ch = s[r];
            m[ch]++;
            maxf = max(maxf, m[ch]);

            while((r - l + 1) - maxf > k) {
                m[s[l]]--;
                l++;
            }

            mx = max(mx, r - l + 1);

            r++;
        }
        return mx;
    }
};
