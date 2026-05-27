class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        if(i==m || j==n || grid[i][j]=='#') return;
        
        grid[i][j]='#';
        if(i>0 && grid[i-1][j]=='1') dfs(grid,i-1,j,m,n);
        if(j>0 && grid[i][j-1]=='1') dfs(grid,i,j-1,m,n);
        if(i<m-1 && grid[i+1][j]=='1') dfs(grid,i+1,j,m,n);
        if(j<n-1 && grid[i][j+1]=='1') dfs(grid,i,j+1,m,n);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(),count=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1') 
                {
                    dfs(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};
