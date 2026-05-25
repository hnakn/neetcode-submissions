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
            return a.start<b.start;
        }
    };
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int i=0,result=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        while(i<intervals.size())
        {
            if(pq.empty() || intervals[i].start<pq.top())
            {
                pq.push(intervals[i].end);
            }
            else if(intervals[i].start>=pq.top())
            {
                pq.pop();
                pq.push(intervals[i].end);
            }
            i++;
            result = max(result,int(pq.size()));
        }
        return result;
    }
};
