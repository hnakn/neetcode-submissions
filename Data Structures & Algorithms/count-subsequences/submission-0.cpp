class Solution {
public:
    int sol(string s, string t, int i, int j, unordered_map<int,unordered_map<string,int>>& dp, string curr)
    {
        if(i==s.size() || j==t.size())
        {
            if(curr==t) return 1;
            else return 0;
        }
        if(dp[i].count(curr)) return dp[i][curr];
        int pick=0;
        if(s[i]==t[j]) pick = sol(s,t,i+1,j+1,dp,curr+s[i]);
        int notpick = sol(s,t,i+1,j,dp,curr);
        return dp[i][curr] = pick + notpick;
    }
    int numDistinct(string s, string t) {
        unordered_map<int,unordered_map<string,int>> dp;
        return sol(s,t,0,0,dp,"");
    }
};
