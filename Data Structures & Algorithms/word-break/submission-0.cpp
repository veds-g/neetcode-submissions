class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (auto& word : words) {
                int len = word.size();

                // word can only end at position i if len <= i
                if (len > i) continue;

                // check if word matches s[i-len..i-1]
                if (s.substr(i - len, len) == word) {
                    // if s[0..i-len-1] was segmentable, then s[0..i-1] is too
                    if (dp[i - len]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};
