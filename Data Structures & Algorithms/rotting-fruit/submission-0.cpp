class Solution {
public:
    int maxi = 0;
    void bfs(vector<vector<int>>& grid,int i,int j,int m,int n,int t)
    {
        if(i>=m || j>=n || i<0 || j<0) return;
        grid[i][j]=-1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{i,j},t});
        maxi=max(t,maxi);
        while(!q.empty())
        {
            int a = q.front().first.first;
            int b = q.front().first.second;
            int time = q.front().second;
            q.pop();
            if(i>0 && grid[i-1][j]==1) bfs(grid,i-1,j,m,n,time+1);
            if(j>0 && grid[i][j-1]==1) bfs(grid,i,j-1,m,n,time+1);
            if(i<m-1 && grid[i+1][j]==1) bfs(grid,i+1,j,m,n,time+1);
            if(j<n-1 && grid[i][j+1]==1) bfs(grid,i,j+1,m,n,time+1);
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
    
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    bfs(grid,i,j,m,n,0);
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return maxi;
    }
};
