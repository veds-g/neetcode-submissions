class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> l(n, -1), r(n, n);
        stack<int> stk;

        for (int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
            if (!stk.empty()) r[i] = stk.top();
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for (int i = 0; i < n; i++) {
           while(!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
            if (!stk.empty()) l[i] = stk.top();
            stk.push(i);
        } 

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, h[i] * (r[i] - l[i] - 1));
        }

        return ans;
    }
};
