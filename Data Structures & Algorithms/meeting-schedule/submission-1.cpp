/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& v) {
        vector<vector<int>> intervals;
        for(auto x : v) {
            intervals.push_back({x.start, x.end});
        }
        if (intervals.size() == 0) return true;
        
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        vector<int> curr = intervals[0];

        for (int i = 1; i < n; i++) {
            if (curr[1] <= intervals[i][0]) {
                curr = intervals[i];
            } else {
                return false;
            }
        }

        return true;
    }
};
