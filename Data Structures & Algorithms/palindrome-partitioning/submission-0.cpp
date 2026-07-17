class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        string curr = "";
        solve(0, s, curr, temp, ans);
        return ans;
    }

    void solve(int idx, string& s, string& curr, vector<string>& temp, vector<vector<string>>& ans) {
        if (idx == s.size()) {
            if (curr.empty()) {
                ans.push_back(temp);
            }
            return;
        }

        curr.push_back(s[idx]);

        // 2 choices
        // consider palindrome till idx
        if (isPalin(curr)) {
            temp.push_back(curr);
            curr = "";
            solve(idx + 1, s, curr, temp, ans);
            curr = temp.back();
            temp.pop_back();
        }

        // consider palindrome later
        solve(idx + 1, s, curr, temp, ans);
        curr.pop_back(); 
    }

    bool isPalin(string& curr) {
        int l = 0, r = curr.size() - 1;
        while (l <= r) {
            if (curr[l] != curr[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
