class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n, 0, 0, temp, ans);
        return ans;
    }

    void solve(int n, int open, int close, string& temp, vector<string>& ans) {
        if (open == n and close == n) { 
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            temp += "(";
            solve(n, open + 1, close, temp, ans);
            temp.pop_back();
        }

        if (close < open) {
            temp += ")";
            solve(n, open, close + 1, temp, ans);
            temp.pop_back();
        }
    }
};
