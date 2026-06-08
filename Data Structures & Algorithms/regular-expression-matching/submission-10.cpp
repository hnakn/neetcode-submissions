class Solution {
public:
    bool sol(string& s, string& p, int i, int j,vector<vector<int>>& dp)
    {
        if(i==s.size() && j==p.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool result = false;
        if(i<s.size() && (s[i]==p[j] || p[j]=='.')) result = result || sol(s,p,i+1,j+1,dp);
        if(j<p.size()-1 && p[j+1]=='*')
        {
            result = result || sol(s,p,i,j+2,dp);
            if(i<s.size() && (s[i]==p[j] || p[j]=='.'))
            {
                result = result || sol(s,p,i+1,j,dp);
            }
        }        
        return dp[i][j] = result;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return sol(s,p,0,0,dp);
    }
};
