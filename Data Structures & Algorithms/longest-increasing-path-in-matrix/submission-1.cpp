class Solution {
public:
    int sol(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        if(i==m || j==n || i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0,right=0,up=0,down=0;
        if(i>0 && matrix[i-1][j]>matrix[i][j]) up = sol(matrix, i-1, j, m, n, dp);
        if(i<m-1 && matrix[i+1][j]>matrix[i][j]) down = sol(matrix, i+1, j, m, n, dp);
        if(j>0 && matrix[i][j-1]>matrix[i][j]) left = sol(matrix, i, j-1, m, n, dp);
        if(j<n-1 && matrix[i][j+1]>matrix[i][j]) right = sol(matrix, i, j+1, m, n, dp);
        return dp[i][j] = max(left,max(right,max(up,down))) + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size(),result=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                result = max(result, sol(matrix, i, j, m, n, dp));
            }
        }
        return result;
    }
};
