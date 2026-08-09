class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0, n = intervals.size();
        
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);

        vector<int> curr = intervals[0];

        for (int i = 1; i < n; i++) {
            if (curr[1] <= intervals[i][0]) {
                curr = intervals[i];
            } else {
                cnt++;
                if (intervals[i][1] < curr[1]) {
                    curr = intervals[i];
                }
            }
        }

        return cnt;
    }
};
