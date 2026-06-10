class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<pair<int,int>> temp;
        for(int i=0;i<queries.size();i++)
        {
            temp.push_back({queries[i],i});
        }

        vector<int> result(queries.size(),0);
        sort(temp.begin(),temp.end());
        sort(intervals.begin(),intervals.end());
        int x = 0;
        for(auto& i : temp)
        {
            while(x<intervals.size() && intervals[x][0]<=i.first) 
            {
                pq.push({intervals[x][1]-intervals[x][0]+1, intervals[x][1]});
                x++;
            }
            while(!pq.empty() && pq.top().second<i.first) pq.pop();
            if(!pq.empty())
            {
                result[i.second] = pq.top().first;
            } 
            else 
            {
                result[i.second] = -1;
            }
        }

        return result;
    }
};
