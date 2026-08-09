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
            return a.end < b.end;
        return a.start < b.start;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), mycmp);

        int n = intervals.size();
        multiset<int> s;

        for (auto& interval : intervals) {
            if (s.empty()) {
                s.insert(interval.end);
            } else if (interval.start < *s.begin()) {
                s.insert(interval.end);
            } else {
                s.erase(s.begin());
                s.insert(interval.end);
            }
        }

        return s.size();
    }
};