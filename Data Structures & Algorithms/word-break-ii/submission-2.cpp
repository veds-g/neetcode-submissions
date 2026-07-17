class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<string> ans;
        string temp = "";
        solve(0, s, temp, ans, wordSet);
        return ans;
    }

    void solve(int idx, string& s, string& temp, vector<string>& ans, unordered_set<string>& wordSet) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int end = idx; end < s.size(); end++) {
            string word = s.substr(idx, end - idx + 1);
            if (wordSet.contains(word)) {
                string savedTemp = temp;
                if (!temp.empty()) temp += ' ';
                temp += word;
                solve(end + 1, s, temp, ans, wordSet);
                temp = savedTemp;
            }
        }
    }
};