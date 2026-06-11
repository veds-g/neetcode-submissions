class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        
        for(auto&x : t) {
            if (x == "+") {
                int e1 = s.top(); s.pop();
                int e2 = s.top(); s.pop();
                s.push(e1 + e2);
            } else if (x == "-") {
                int e1 = s.top(); s.pop();
                int e2 = s.top(); s.pop();
                s.push(e2 - e1);
            } else if (x == "*") {
                int e1 = s.top(); s.pop();
                int e2 = s.top(); s.pop();
                s.push(e1 * e2);
            } else if (x == "/") {
                int e1 = s.top(); s.pop();
                int e2 = s.top(); s.pop();
                s.push(e2 / e1);
            } else {
                s.push(stoi(x));
            }
        }

        return s.top();
    }
};
