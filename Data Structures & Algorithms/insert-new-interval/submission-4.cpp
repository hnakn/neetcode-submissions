class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>> result;
        while(i<intervals.size() && intervals[i][0]<newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        vector<int> curr;

        if(i>0 && intervals[i-1][1]>newInterval[0]) 
        {
            if(!result.empty()) result.pop_back();
            curr = {intervals[i-1][0], max(intervals[i-1][1],newInterval[1])};
        }
        else
        {
            curr = newInterval;
        }

        
        while(i<intervals.size())
        {
            if(intervals[i][0]<=curr[1])
            {
                curr[1] = max(curr[1],intervals[i][1]);
            }
            else
            {
                result.push_back(curr);
                curr = intervals[i];
            }
            i++;
        }
        result.push_back(curr);
        return result;        
    }
};
