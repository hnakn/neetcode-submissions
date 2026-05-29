class Solution {
public:
    int sol(vector<int>& coins, int amount)
    {
        if(amount==0) return 0;
        int mini = INT_MAX;
        for(int i : coins)
        {
            if(amount-i>=0)
            {
                int res = sol(coins, amount-i);
                mini = min(mini, res+1);
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int result = sol(coins, amount);
        if(result==INT_MIN) return -1;
        return result;
    }
};
