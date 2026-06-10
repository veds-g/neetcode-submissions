class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), ans = 0;
        unordered_set<char> st;
        while (r < n) {
            if (!st.contains(s[r])) {
                ans = max(ans, r - l + 1);
                st.insert(s[r]);
            } else {
                while (s[l] != s[r]) {
                    st.erase(s[l++]);
                }
                l++;
            }
            r++;
        }

        return ans;
    }
};
