class Solution {
public:
    bool sol(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp)
    {
        if(i>s1.size() || j>s2.size() || i+j>s3.size()) return false;
        if(i+j==s3.size() && i==s1.size() && j==s2.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool result = false;
        if(s1[i]==s3[i+j]) result = result || sol(s1,s2,s3,i+1,j,dp);
        if(s2[j]==s3[i+j]) result = result || sol(s1,s2,s3,i,j+1,dp);
        return dp[i][j]=result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return sol(s1,s2,s3,0,0,dp);
    }
};
