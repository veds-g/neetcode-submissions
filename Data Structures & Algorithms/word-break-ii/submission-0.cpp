class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<string> ans;
        string curr = "", temp = "";
        solve(0, s, curr, temp, ans, wordSet);
        return ans;
    }

    void solve(int idx, string& s, string& curr, string& temp, vector<string>& ans, unordered_set<string>& wordSet) {
        if (idx == s.size()) {
            if (curr.empty()) {
                ans.push_back(temp);
            }
            return;
        }

        curr.push_back(s[idx]);

        if (wordSet.contains(curr)) {
            string saved = curr;
            string savedTemp = temp;

            if (!temp.empty()) temp.push_back(' ');
            temp += curr;
            curr = "";

            solve(idx + 1, s, curr, temp, ans, wordSet);

            curr = saved;
            temp = savedTemp;
        }

        solve(idx + 1, s, curr, temp, ans, wordSet);

        curr.pop_back();
    }

    string getLastWord(string str) {
        if (str.empty()) {
            return "";
        }
        size_t lastSpace = str.find_last_of(' ');

        if (lastSpace == string::npos) {
            return str;
        }

        return str.substr(lastSpace + 1);
    }
};