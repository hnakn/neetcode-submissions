class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=prices.size()-1,result=0;
        while(l<r)
        {
            result = max(result, prices[r]-prices[l]);
            if(prices[l]>prices[r]) l++;
            else r--;
        }
        return result;        
    }
};
