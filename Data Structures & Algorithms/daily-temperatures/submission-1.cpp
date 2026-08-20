class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> ans(n, 0);

        stk.push(0);
        for (int i = 1; i < n; i++) {
            while (!stk.empty() and temperatures[stk.top()] < temperatures[i]) {
                int idx = stk.top();
                ans[idx] = i - idx;
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};
