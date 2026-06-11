class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<string> stk;

        for(int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                string tmp = "";
                while (stk.top() != "[") {
                    tmp = stk.top() + tmp;
                    stk.pop();
                }
                stk.pop();
                int cnt = stoi(stk.top());
                stk.pop();
                string updated = "";
                for (int j = 0; j < cnt; j++)
                    updated += tmp;
                stk.push(updated);
            } else {
                string temp;
                if (isdigit(s[i])) {
                    while (i < s.size() && isdigit(s[i])) 
                        temp += s[i++];
                    i--;
                } else {
                    temp += s[i];
                } 
                stk.push(temp);
            }
        }

        while(!stk.empty()) ans = stk.top() + ans, stk.pop();
        return ans;
    }
};