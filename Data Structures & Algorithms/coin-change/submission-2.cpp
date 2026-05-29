class Solution {
public:
    int sol(vector<int>& coins, int amount,vector<int>& dp)
    {
        if(amount==0) return 0;
        int mini = INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        for(int i : coins)
        {
            if(amount-i>=0)
            {
                int res = sol(coins, amount-i,dp);
                mini = min(mini, res+1);
            }
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int result = sol(coins, amount,dp);
        if(result==INT_MIN || result==INT_MAX) return -1;
        return result;
    }
};
