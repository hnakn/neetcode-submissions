class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int dist = pow(0-points[i][0],2) + pow(0-points[i][1],2);
            pq.push({dist, points[i]});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> result;
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        
    }
};
