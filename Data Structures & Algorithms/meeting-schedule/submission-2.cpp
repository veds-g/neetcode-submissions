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
    static bool mycmp(Interval& a, Interval& b){
        if(a.start == b.start)
            return a.end <= b.end;
        return a.start < b.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end(), mycmp);

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
