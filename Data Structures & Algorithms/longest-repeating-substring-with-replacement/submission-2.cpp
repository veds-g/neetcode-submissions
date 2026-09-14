class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, n = s.size();
        int mx = INT_MIN, mf = 0;

        while(r < n) {
            mp[s[r]]++;
            mf = max(mf, mp[s[r]]);

            while((r - l + 1) - mf > k ) {
                mp[s[l]]--;
                l++;
            }

            mx = max(mx, r - l + 1);
            r++;
        }

        return mx;
    }
};
