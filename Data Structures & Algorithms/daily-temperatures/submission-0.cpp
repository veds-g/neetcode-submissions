class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty()) {
                stk.push({i, temp[i]});
            } else {
                while (!stk.empty() and temp[i] > stk.top().second) {
                    pair<int, int> p = stk.top();
                    res[p.first] = i - p.first;
                    stk.pop();
                }
                stk.push({i, temp[i]});
            }
        }

        return res;
    }
};
