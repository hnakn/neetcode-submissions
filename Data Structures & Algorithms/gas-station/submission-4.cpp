class Solution {
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas=0,tcost=0,index=0,tot=0;
        for(int i=0;i<cost.size();i++)
        {
            tgas += gas[i];
            tcost += cost[i];
            tot += gas[i]-cost[i];
            if(tgas<tcost)
            {
                index = i+1;
                tgas = 0;
                tcost = 0;
            }
        }      
        if(tot>=0) return index;  
        return -1;
    }
};
