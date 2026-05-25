class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int i=1;
        vector<int> curr = intervals[0];
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
