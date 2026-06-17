class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                mp[i].push_back({j,dist});
                mp[j].push_back({i,dist});
            }
        }

        int result=0;
        unordered_set<int> st;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<mp[0].size();i++)
        {
            pq.push({mp[0][i].second,mp[0][i].first});
        }
        st.insert(0);
        while(st.size()<points.size())
        {
            while(st.count(pq.top().second)) pq.pop();
            result += pq.top().first;
            int curr = pq.top().second;
            st.insert(curr);
            pq.pop();
            for(int i=0;i<mp[curr].size();i++)
            {
                if(st.count(mp[curr][i].first)) continue;
                pq.push({mp[curr][i].second,mp[curr][i].first});
            }
        }
        return result;
    }
};
