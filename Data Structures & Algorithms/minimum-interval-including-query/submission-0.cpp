class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<queries.size();i++)
        {
            mp[queries[i]]=i;
        }
        vector<int> result(queries.size(),0);
        sort(queries.begin(),queries.end());
        sort(intervals.begin(),intervals.end());
        int x = 0;
        for(int i : queries)
        {
            while(x<intervals.size() && intervals[x][0]<=i) 
            {
                pq.push({intervals[x][1]-intervals[x][0]+1, intervals[x][1]});
                x++;
            }
            while(!pq.empty() && pq.top().second<i) pq.pop();
            if(!pq.empty()) result[mp[i]] = pq.top().first;
            else result[mp[i]]=-1;
        }

        return result;
    }
};
