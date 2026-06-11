class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (const int& x : asteroids) {
            stk.push(x);
            while (stk.size() > 1) {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();

                if (a < 0 && b >= 0) {
                    if (abs(a) > abs(b)) stk.push(a);
                    else if (abs(b) > abs(a)) stk.push(b);
                } else {
                    stk.push(b);
                    stk.push(a);
                    break;
                }
            }
        }
        vector<int> ans;
        while (!stk.empty()) ans.push_back(stk.top()), stk.pop();
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};