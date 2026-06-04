class Solution {
public:
    int maxi(vector<int>& prices, int index, bool buy,vector<vector<int>>& dp)
    {
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int x=INT_MIN,y=INT_MIN;
        if(buy)
        {
            x = prices[index] + maxi(prices,index+2,false,dp);
            y = maxi(prices,index+1,true,dp);
        }
        else if(!buy)
        {
            x = -prices[index] + maxi(prices,index+1,true,dp);
            y = maxi(prices,index+1,false,dp);
        }
        return dp[index][buy] = max(x,y);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return maxi(prices,0,false,dp);
    }
};
