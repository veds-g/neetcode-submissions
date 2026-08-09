class Solution {
public:
    bool checkValidString(string s) {
        int count = 0;

        stack<int> open, star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open.push(i);
            else if (s[i] == '*') star.push(i);
            else {
                if (open.size()) open.pop();
                else if (star.size()) star.pop();
                else return false;
            }
        }

        while (open.size() and star.size()) {
            int openIdx = open.top();
            int starIdx = star.top();

            if (openIdx > starIdx) return false;
            open.pop();
            star.pop();
        }

        return open.size() == 0;
    }
};
