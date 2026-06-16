class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj(n,vector<int>(n,-1));
        for(auto& it : times)
        {
            adj[it[0]-1][it[1]-1] = it[2];
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(n,0);
        pq.push({0,k-1});

        int time = INT_MAX,count=0;
        
        while(!pq.empty())
        {
            pair<int,int> temp = pq.top();
            pq.pop();
            time = temp.first;
            if(vis[temp.second]==1) continue;
            vis[temp.second]=1;
            count++;
            if(count==n) return time;
            for(int j=0;j<n;j++)
            {
                if(adj[temp.second][j]!=-1 && vis[j]!=1)
                {
                    pq.push({temp.first+adj[temp.second][j],j});
                }
            }
        }
        return -1;
    }
};
