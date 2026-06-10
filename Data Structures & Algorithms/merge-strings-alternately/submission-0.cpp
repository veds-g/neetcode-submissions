class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size(), l1 = 0, l2 = 0;
        string ans = "";

        while (l1 < s1 || l2 < s2) {
            if (l1 < s1) ans += word1[l1++];
            if (l2 < s2) ans += word2[l2++];
        }

        return ans;
    }
};