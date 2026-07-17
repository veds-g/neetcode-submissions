class Solution {
private:
unordered_map<char, string> digitMap;

void updateDigitMap() {
    digitMap['2'] = "abc";
    digitMap['3'] = "def";
    digitMap['4'] = "ghi";
    digitMap['5'] = "jkl";
    digitMap['6'] = "mno";
    digitMap['7'] = "pqrs";
    digitMap['8'] = "tuv";
    digitMap['9'] = "wxyz";
}
public:
    vector<string> letterCombinations(string digits) {
        updateDigitMap();
        vector<string> ans;
        if (digits.empty()) return ans;
        string comb = "";
        combine(0, digits, comb, ans);
        return ans;
    }

    void combine(int idx, string& digits, string& comb, vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(comb);
            return;
        }

        for (const char& ch : digitMap[digits[idx]]) {
            comb.push_back(ch);
            combine(idx + 1, digits, comb, ans);
            comb.pop_back();
        }
    }
};
