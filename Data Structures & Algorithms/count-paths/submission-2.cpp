class Solution {
public:
    int sol(int m, int n, int i, int j, vector<vector<int>>& dp)
    {
        if(i>=m || i<0 || j>=n || j<0) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = sol(m,n,i,j+1,dp);
        int down = sol(m,n,i+1,j,dp);
        
        return dp[i][j] = right  + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return sol(m,n,0,0,dp);
    }
};
