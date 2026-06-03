class Solution {
public:
    bool sol(vector<int>& gas, vector<int>& cost, int index, int curr, int count, int steps)
    {
        if(steps==count) return true;
        if(curr+gas[index] < cost[index]) return false;
        return sol(gas, cost, (index+1)%count, curr+gas[index]-cost[index],count,steps+1);
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count = gas.size();
        for(int i=0;i<count;i++)
        {
            if(sol(gas,cost,i,0,count,0)) return i;
        }
        return -1;
    }
};
