class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;

        for(auto& it : flights)
        {
            mp[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        vector<unordered_set<int>> vis(n);

        int result = INT_MAX;
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int t = pq.top().second.second;
            pq.pop();
            if(node==dst) result=min(result,cost);
            if(t>k || vis[node].count(t)==1) continue;
            vis[node].insert(t);
            for(auto& i : mp[node])
            {
                pq.push({cost+i.second,{i.first,t+1}});
            } 
        }
        if(result==INT_MAX) return -1;
        return result;
    }
};
