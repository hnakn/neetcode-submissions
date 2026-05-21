class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0],result=0;
        for(int i=0;i<prices.size();i++)
        {
            result = max(result,prices[i]-mini);
            mini = min(mini, prices[i]);
        }
        return result;        
    }
};
