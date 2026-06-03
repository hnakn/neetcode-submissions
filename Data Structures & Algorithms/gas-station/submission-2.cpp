class Solution {
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot=0,curr=0,index=0;
        for(int i=0;i<cost.size();i++)
        {
            int diff = gas[i]-cost[i];
            tot += diff;
            curr += diff;
            if(curr<0)
            {
                index = i+1;
                curr = 0;
            }
        }      
        if(tot>=0) return index;  
        return -1;
    }
};
