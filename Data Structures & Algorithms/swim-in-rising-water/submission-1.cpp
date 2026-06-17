class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        int m = grid.size(), n = grid[0].size(),t=0;
        vector<vector<int>> vis(m,vector<int>(n,0));

        while(!pq.empty())
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int t = pq.top().first;
            pq.pop();
            if(vis[i][j]==1) continue;
            vis[i][j]=1;
            if(i==m-1 && j==n-1) return t;         
            if(i>0) pq.push({max(t,grid[i-1][j]),{i-1,j}});
            if(j>0) pq.push({max(t,grid[i][j-1]),{i,j-1}}); 
            if(i<m-1) pq.push({max(t,grid[i+1][j]),{i+1,j}}); 
            if(j<n-1) pq.push({max(t,grid[i][j+1]),{i,j+1}});           
        }
        return t;
    }
};
