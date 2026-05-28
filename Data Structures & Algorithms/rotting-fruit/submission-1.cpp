class Solution {
public:
   
    int orangesRotting(vector<vector<int>>& grid) {
    
        int m=grid.size(),n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        int maxi = 0;
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            grid[i][j]=2;
            int time = q.front().second;
            maxi=max(maxi,time);
            q.pop();
            if(i>0 && grid[i-1][j]==1) q.push({{i-1,j},time+1});
            if(j>0 && grid[i][j-1]==1) q.push({{i,j-1},time+1});
            if(i<m-1 && grid[i+1][j]==1) q.push({{i+1,j},time+1});
            if(j<n-1 && grid[i][j+1]==1) q.push({{i,j+1},time+1});
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
