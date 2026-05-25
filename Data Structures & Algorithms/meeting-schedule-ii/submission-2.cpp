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
    struct cmp{
        bool operator() (Interval a, Interval b){
            return a.end<b.end;
        }
    };
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int i=0,result=0;
        int curr = INT_MAX;
        while(i<intervals.size())
        {
            if(intervals[i].start<curr)
            {
                result++;
                curr = intervals[i].end;
            }
            else
            {
                curr = min(curr, intervals[i].end);
            }
            i++;
        }
        return result;
    }
};
