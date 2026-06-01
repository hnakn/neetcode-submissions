class Solution {
public:
    bool sol(string& s, vector<string>& wordDict, int index, vector<int>& dp)
    {
        if(index>=s.size()) return true;
        if(dp[index]!=-1) return dp[index];
        bool flag = false;
        for(int i=0;i<wordDict.size();i++)
        {
            int x = 0, y=index;
            while(x<wordDict[i].size() && y<s.size() && s[y]==wordDict[i][x])
            {
                x++;
                y++;
            }
            if(x==wordDict[i].size()) 
            {
                flag = sol(s,wordDict,y,dp);
                break;
            }
        }
        return dp[index] = flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        return sol(s,wordDict,0,dp);
    }
};
