class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> stk;
        for (string& s : op) {
            if (s == "+") {
                int ele1 = stk.top();
                stk.pop();
                int ele2 = stk.top();
                stk.push(ele1);
                stk.push(ele1 + ele2);
            } else if (s == "C") {
                stk.pop();
            } else if (s == "D") {
                int ele = stk.top();
                stk.push(ele * 2);
            } else {
                stk.push(stoi(s));
            }
        }
        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};