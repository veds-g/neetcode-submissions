class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n = a.size();
        
        int inc = 1, dec = 1, mx = 1;;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] < a[i]) {
                inc = dec + 1;
                dec = 1;
            } else if (a[i - 1] > a[i]) {
                dec = inc + 1;
                inc = 1;
            } else {
                inc = dec = 1;
            }
            mx = max(mx, max(inc, dec));
        }

        return mx;
    }
};