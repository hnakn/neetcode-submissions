class Solution {
public:
    int sol(vector<int>& cost, int index)
    {
        if(index<2) return 0;
        return min(sol(cost,index-1)+cost[index-1],sol(cost,index-2)+cost[index-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return sol(cost,cost.size());
    }
};
