class Solution {
public:
    
    void dfs(vector<vector<int>>& heights, int i, int j, int m, int n, vector<vector<int>>& vis)
    {
        if(vis[i][j]==1) return;
        vis[i][j]=1;
        if(i<m-1 && heights[i][j]<= heights[i+1][j]) dfs(heights,i+1,j,m,n,vis);
        if(i>0 && heights[i][j]<= heights[i-1][j]) dfs(heights,i-1,j,m,n,vis);
        if(j<n-1 && heights[i][j]<= heights[i][j+1]) dfs(heights,i,j+1,m,n,vis);
        if(j>0 && heights[i][j]<= heights[i][j-1]) dfs(heights,i,j-1,m,n,vis);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> visp(m,vector<int>(n,0));
        vector<vector<int>> visa(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            dfs(heights, i, 0, m, n, visp);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights, 0, j, m, n, visp);
        }
        for(int i=0;i<m;i++)
        {
            dfs(heights, i, n-1, m, n, visa);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights, m-1, j, m, n, visa);
        }

        vector<vector<int>> result;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visp[i][j]==1 && visa[i][j]==1) result.push_back({i,j});
            }
        }
        return result;
    }
};
