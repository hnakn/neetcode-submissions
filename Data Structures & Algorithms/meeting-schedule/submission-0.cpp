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
        int curr = intervals[0].end;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start<curr)
            {
                return false;
            }
            curr = max(curr,intervals[i].end);
        }
        return true;
    }
};
