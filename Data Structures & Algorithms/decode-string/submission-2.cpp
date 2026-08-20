class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        unordered_set<string> digits({"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"});

        string ans = "";
        for (auto& c : s) {
            if (c != ']') {
                stk.push(string(1, c));
            } else {
                string repeated = "";
                while (stk.size() and stk.top() != "[") {
                    repeated = stk.top() + repeated;
                    stk.pop();
                }
                stk.pop();

                string timesS = "";
                while (!stk.empty() and digits.contains(stk.top())) {
                    timesS = stk.top() + timesS;
                    stk.pop();
                }
                int times = stoi(timesS);
                string fin = "";
                for (int i = 0; i < times; i++) fin += repeated;
                cout << fin << endl;
                stk.push(fin);
            }
        }

        string remainder = "";
        while (!stk.empty()) {
            remainder = stk.top() + remainder;
            stk.pop();
        }
        ans += remainder;
        return ans;
    }
};