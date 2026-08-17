class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        int n = p.size();
        sort(p.begin(), p.end());

        int cnt = 0, l = 0, r = n - 1;
        while (l <= r) {
            int rem = lim - p[r];
            if (rem >= p[l]) {
                cnt++;
                l++;
                r--;
            } else {
                cnt++;
                r--;
            }
        } 

        return cnt;
    }
};
