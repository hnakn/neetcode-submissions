class Solution {
public:
    bool pac(vector<vector<int>>& heights, int i, int j, int m, int n, vector<vector<int>>& vis)
    {
        if((i==0 || j==0)) return true;
        if(i==m || j==n || vis[i][j]==1) return false;
        vis[i][j]=1;
        bool left=false,right=false,top=false,bottom=false;
        if(i<m-1 && heights[i][j]>= heights[i+1][j]) bottom = pac(heights,i+1,j,m,n,vis);
        if(i>0 && heights[i][j]>= heights[i-1][j]) top = pac(heights,i-1,j,m,n,vis);
        if(j<n-1 && heights[i][j]>= heights[i][j+1]) right = pac(heights,i,j+1,m,n,vis);
        if(j>0 && heights[i][j]>= heights[i][j-1]) left = pac(heights,i,j-1,m,n,vis);
        vis[i][j]=0;
        return left || right || top || bottom;
    }

    bool atl(vector<vector<int>>& heights, int i, int j, int m, int n, vector<vector<int>>& vis)
    {
        if((i==m-1 || j==n-1)) return true;
        if(i<0 || j<0 || vis[i][j]==1) return false;
        vis[i][j]=1;
        bool left=false,right=false,top=false,bottom=false;
        if(i<m-1 && heights[i][j]>= heights[i+1][j]) bottom = atl(heights,i+1,j,m,n,vis);
        if(i>0 && heights[i][j]>= heights[i-1][j]) top = atl(heights,i-1,j,m,n,vis);
        if(j<n-1 && heights[i][j]>= heights[i][j+1]) right = atl(heights,i,j+1,m,n,vis);
        if(j>0 && heights[i][j]>= heights[i][j-1]) left = atl(heights,i,j-1,m,n,vis);
        vis[i][j]=0;
        return left || right || top || bottom;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> result;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pac(heights,i,j,m,n,vis) && atl(heights,i,j,m,n,vis)) result.push_back({i,j});
            }
        }
        return result;
    }
};
