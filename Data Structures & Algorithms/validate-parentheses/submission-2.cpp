class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char& x : s) {
            if (x == ')') {
                if (!stk.empty() and stk.top() == '(') stk.pop();
                else return false;
            }
            else if (x == '}') {
                if (!stk.empty() and stk.top() == '{') stk.pop();
                else return false;
            }
            else if (x == ']') {
                if (!stk.empty() and stk.top() == '[') stk.pop();
                else return false;
            }
            else stk.push(x);
        }
        return stk.empty();
    }
};
