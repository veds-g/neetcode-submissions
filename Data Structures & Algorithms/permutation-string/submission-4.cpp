class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> cnt1(26, 0), cnt2(26,0);

        for (auto& c : s1) cnt1[c - 'a']++;

        int l = 0, r = 0, n = s2.size();
        while (r < n) {
            int ch = s2[r] - 'a';
            cnt2[ch]++;
            r++;

            while (l < r and cnt2[ch] > cnt1[ch]) {
                int chl = s2[l] - 'a';
                cnt2[chl]--, l++;
            }

            if (r - l == s1.size() and cnt1 == cnt2) {
                return true;
            }
        }

        return false;
    }
};
