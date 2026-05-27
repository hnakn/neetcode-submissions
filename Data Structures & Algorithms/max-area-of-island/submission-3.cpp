class Solution {
public:
    int area = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n,int count)
    {
        if(i>m || j>n || grid[i][j]==0) return;
        
        grid[i][j]=0;
        count++;
        area = max(count,area);
        if(i>0 && grid[i-1][j]==1) dfs(grid,i-1,j,m,n,count);
        if(j>0 && grid[i][j-1]==1) dfs(grid,i,j-1,m,n,count);
        if(i<m-1 && grid[i+1][j]==1) dfs(grid,i+1,j,m,n,count);
        if(j<n-1 && grid[i][j+1]==1) dfs(grid,i,j+1,m,n,count);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1) 
                {
                    dfs(grid,i,j,m,n,0);
                }
            }
        }
        return area;
    }
};
