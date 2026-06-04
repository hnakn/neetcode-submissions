class Solution {
public:
    int sol(string text1, string text2, int i, int j, vector<vector<int>>& dp)
    {
        if(i==text1.size() || j==text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int same=INT_MIN;
        if(text1[i]==text2[j]) same = 1 + sol(text1,text2,i+1,j+1,dp);
        return dp[i][j]=max(same, max(sol(text1,text2,i+1,j,dp),sol(text1,text2,i,j+1,dp)));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return sol(text1,text2,0,0,dp);
    }
};
