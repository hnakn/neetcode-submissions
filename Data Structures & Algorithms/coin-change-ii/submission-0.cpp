class Solution {
public:
    int sol(int amount, vector<int>& coins, int curr,int index, vector<vector<int>>& dp)
    {
        if(curr==amount) return 1;
        if(curr>amount) return 0;
        if(dp[index][curr]!=-1) return dp[index][curr];
        int result = 0;
        for(int i=index;i<coins.size();i++)
        {
            result += sol(amount, coins, curr+coins[i], i, dp);
        }
        return dp[index][curr] = result;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount,-1));
        return sol(amount, coins, 0, 0, dp);
    }
};
