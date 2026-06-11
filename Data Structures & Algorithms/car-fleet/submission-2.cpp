class Solution {
public:
    int carFleet(int tar, vector<int>& p, vector<int>& s) {
        int ans = 0, n = p.size();
        vector<pair<int, int>> m(n);
        for (int i = 0; i < n; i++) m[i] = {p[i], s[i]};
        sort(m.begin(), m.end(), greater<pair<int, int>>());
        
        vector<double> t(n);
        for (int i = 0; i < n; i++) 
            t[i] = (tar - m[i].first) / (double)m[i].second;
        
        stack<double> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty()) stk.push(i);
            else {
                double t1 = t[stk.top()];
                double t2 = t[i];
                if (t2 > t1) stk.push(i);
            }
        }

        return stk.size();
    }
};

