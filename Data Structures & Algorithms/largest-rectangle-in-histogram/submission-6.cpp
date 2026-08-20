class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = h[0];
        stack<int> stk;
        stk.push(0);
        h.push_back(0);

        for (int i = 1; i < h.size(); i++) {
            while (!stk.empty() and h[i] <= h[stk.top()]) {
                int idx = stk.top(); stk.pop();
                int left = stk.empty() ? idx : idx - stk.top() - 1;
                int right = i - idx - 1;
                int area = h[idx] * (left + right + 1);
                ans = max(ans, area);
            }
            stk.push(i);
        }

        return ans;
    }
};
