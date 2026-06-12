class Solution {
public:
    string simplifyPath(string p) {
        vector<string> stk;

        int l = -1, r = 0, n = p.size();

        while (r < n) {
            string temp;
            while (r < n && p[r] == '/') r++;
            if (r == n) break;
            l = r;
            while (r < n && p[r] != '/') r++;
            temp = p.substr(l, r - l);

            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!stk.empty()) stk.pop_back(); 
            } else {
                stk.push_back(temp);
            }
        }

        string ans;
        for (const string& seg : stk) {
            ans += '/' + seg;
        }

        if (ans.empty()) return "/";

        return ans;
    }
};