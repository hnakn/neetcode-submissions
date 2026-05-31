class Solution {
public:
   
    bool sol(string& s, int i, int j, vector<vector<int>>& dp)
    {
        if(i>=s.size() || j<0) return false;
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return dp[i][j]=false;
        else return dp[i][j] = sol(s,i+1,j-1,dp);
    }
    string longestPalindrome(string s) {
        string result = "";
        int size = 0;
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(sol(s,i,j,dp)) 
                {
                    if(j-i+1>size)
                    {
                        size=j-i+1;
                        result = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return result;
    }
};
