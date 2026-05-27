class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n,vector<vector<int>>& vis)
    {
        if(i==m || j==n || vis[i][j]==1) return;
        vis[i][j]=1;
        if(i>0 && grid[i-1][j]=='1') dfs(grid,i-1,j,m,n,vis);
        if(j>0 && grid[i][j-1]=='1') dfs(grid,i,j-1,m,n,vis);
        if(i<m-1 && grid[i+1][j]=='1') dfs(grid,i+1,j,m,n,vis);
        if(j<n-1 && grid[i][j+1]=='1') dfs(grid,i,j+1,m,n,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(),count=0;
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1' && vis[i][j]==0) 
                {
                    dfs(grid,i,j,m,n,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
