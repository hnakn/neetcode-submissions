class Solution {
public:
    int maxi(vector<int>& prices, int index, bool buy, bool sell, int curr,vector<vector<int>>& dp)
    {
        if(index>=prices.size()) return curr;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int x=INT_MIN,y=INT_MIN;
        if(buy)
        {
            x = maxi(prices,index+2,false,true,curr+prices[index],dp);
            y = maxi(prices,index+1,true,false,curr,dp);
        }
        else if(sell)
        {
            x = maxi(prices,index+1,true,false,curr-prices[index],dp);
            y = maxi(prices,index+1,false,true,curr,dp);
        }
        return dp[index][buy] = max(x,y);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return maxi(prices,0,false,true,0,dp);
    }
};
