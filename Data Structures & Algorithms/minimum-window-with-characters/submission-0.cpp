class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> m1, m2;
        for (auto& x : t) m2[x]++;

        int l = 0, have = 0, need = m2.size(), ans = INT_MAX;
        pair<int, int> p;
        for (int r = 0; r < s.size(); r++) {
            char ch = s[r];
            m1[ch]++;

            if (m1[ch] == m2[ch]) have++;

            while (have == need) {
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    p = {l , r};
                }

                m1[s[l]]--;
                if (m1[s[l]] < m2[s[l]]) have--;
                l++;
            }
        }

        return ans == INT_MAX ? "" :  s.substr(p.first, ans);
    }
};
