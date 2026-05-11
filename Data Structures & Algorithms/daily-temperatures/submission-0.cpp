class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int n = temperatures.size();
        vector<int> results(n,0);
        for(int i=0;i<n;i++)
        {
            if(stk.empty() || stk.top().first>=temperatures[i]) stk.push({temperatures[i],i});
            while(!stk.empty() && stk.top().first<temperatures[i])
            {
                results[stk.top().second] = i-stk.top().second;
                stk.pop();                
            }
            stk.push({temperatures[i],i});
        }
        return results;
                
    }
};
