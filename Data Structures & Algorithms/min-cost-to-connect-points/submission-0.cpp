class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> vis(points.size(),0);
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push({dist,{i,j}});
            }
        }

        int count = 0,result=0;
        while(!pq.empty() && count<points.size()-1)
        {
            if(vis[pq.top().second.first]==1 && vis[pq.top().second.second]==1)
            {
                pq.pop();
                continue;
            }
            count++;
            result += pq.top().first;
            vis[pq.top().second.first]=1;
            vis[pq.top().second.second]=1;

            pq.pop();
        }
        return result;
    }
};
