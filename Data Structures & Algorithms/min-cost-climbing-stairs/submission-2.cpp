class Solution {
public:
    int sol(vector<int>& cost, int index,vector<int>& dp)
    {
        if(index<2) return 0;
        if(dp[index]!=-1) return dp[index];
        return dp[index] = min(sol(cost,index-1,dp)+cost[index-1],sol(cost,index-2,dp)+cost[index-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return sol(cost,n,dp);
    }
};
