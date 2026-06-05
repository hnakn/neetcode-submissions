class Solution {
public:
    int sol(string& word1, string& word2, int i, int j, vector<vector<int>>& dp)
    {
        if(j==word2.size()) return word1.size()-i;
        if(i==word1.size()) return word2.size()-j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) 
        {
            return dp[i][j] = sol(word1,word2,i+1,j+1,dp);
        }
        int ins = sol(word1, word2, i, j+1, dp);
        int del = sol(word1, word2, i+1, j, dp);
        int repl = sol(word1, word2, i+1, j+1, dp);
        return dp[i][j] = 1+min(ins,min(del,repl));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size(),-1));
        return sol(word1,word2,0,0,dp);
    }
};
