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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) return true;
        auto cmp = [](const Interval& a, const Interval& b) {
            if (a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), cmp);

        int n = intervals.size();

        auto curr = intervals[0];

        for (int i = 1; i < n; i++) {
            if (curr.end <= intervals[i].start) {
                curr = intervals[i];
            } else {
                return false;
            }
        }

        return true;
    }
};
