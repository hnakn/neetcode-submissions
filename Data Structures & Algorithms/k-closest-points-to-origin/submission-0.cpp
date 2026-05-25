class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int dist = sqrt(pow(0-points[i][0],2) + pow(0-points[i][1],2));
            pq.push({dist, points[i]});
        }

        int count = 0;
        vector<vector<int>> result;
        while(count<k && !pq.empty())
        {
            count++;
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        
    }
};
