class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.size();

        unordered_map<char, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            if (!mp.contains(s[i])) mp[s[i]] = i;
        }

        unordered_set<int> st;
        int maxIdx = 0, prevIdx = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            maxIdx = max(maxIdx, mp[ch]);

            if (maxIdx == i) {
                ans.push_back(maxIdx - prevIdx + 1);
                prevIdx = i + 1;
            }
        }

        return ans;
    }
};
