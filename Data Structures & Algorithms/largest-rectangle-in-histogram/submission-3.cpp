class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> stk;
        int ans = INT_MIN;


        for (int i = 0; i <= n; i++) {
           while(!stk.empty() and (i == n || h[stk.top()] >= h[i])) {
                int height = h[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                ans = max(ans, height * width);
            }
            stk.push(i);
        } 

        return ans;
    }
};
