class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int result = 0;
        int curr_min = INT_MAX;
        for(auto& p : intervals)
        {
            if(p[0]<curr_min)
            {
                curr_min = min(curr_min, p[1]);
                cout << curr_min;
                result++;
            }
            else
            {
                curr_min = p[1];
            }
        }
        return result-1;
        
    }
};
