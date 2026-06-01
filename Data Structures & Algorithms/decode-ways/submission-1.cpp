class Solution {
public:
    int sol(string& s, int index, vector<int>& dp)
    {
        if(index==s.size()) return 1;
        if(s[index]-'0'==0) return 0;
        if(dp[index]!=-1) return dp[index];
        for(int i=1;i<=2;i++)
        {
            if(index+i>s.size()) continue;
            string curr = s.substr(index,i);
            if(stoi(curr)<=26 && stoi(curr)>0)
            {
                if(dp[index]==-1) dp[index]=sol(s,index+i,dp);
                else dp[index]+= sol(s,index+i,dp);
            }
        }
        return dp[index];
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return sol(s,0,dp);
    }
};
