class Solution {
public:
    int maxi(vector<int>& prices, int index, bool buy, bool sell, int curr)
    {
        if(index>=prices.size()) return curr;
        int x=INT_MIN,y=INT_MIN;
        if(buy)
        {
            x = maxi(prices,index+2,false,true,curr+prices[index]);
            y = maxi(prices,index+1,true,false,curr);
        }
        else if(sell)
        {
            x = maxi(prices,index+1,true,false,curr-prices[index]);
            y = maxi(prices,index+1,false,true,curr);
        }
        return max(x,y);
    }
    int maxProfit(vector<int>& prices) {
        return maxi(prices,0,false,true,0);
    }
};
