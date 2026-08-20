class Solution {
public:
    string simplifyPath(string path) {
        string word = "";
        stack<string> stk;
        path.push_back('/');
        
        for (auto& ch : path) {
            if (ch == '/') {
                if (!word.empty()) {
                    if (word != "." and word != "..") {
                        stk.push(word);
                    } else if (word == "..") {
                        if (!stk.empty()) {
                            stk.pop();
                        }
                    }
                    word = "";
                }
            } else {
                word += ch;
            }
        }

        string ans = "";
        while (!stk.empty()) {
            string ele = stk.top(); stk.pop();
            reverse(ele.begin(), ele.end());
            ans += ele;
            ans += "/";
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty()) return "/";
        return ans;
    }
};