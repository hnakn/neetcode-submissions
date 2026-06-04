class Solution {
public:
    int sol(int m, int n, vector<vector<int>>& vis, int i, int j, vector<vector<int>>& dp)
    {
        if(i>=m || i<0 || j>=n || j<0) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        vis[i][j]=1;
        int right = sol(m,n,vis,i,j+1,dp);
        int down = sol(m,n,vis,i+1,j,dp);
        vis[i][j]=0;
        return dp[i][j] = right  + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return sol(m,n,vis,0,0,dp);
    }
};
