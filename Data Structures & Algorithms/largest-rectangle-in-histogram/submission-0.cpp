class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;
        int last,maxi = INT_MIN,flag=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!stk.empty() && stk.top().first>heights[i])
            {
                maxi = max(maxi,(i-stk.top().second)*stk.top().first);
                last = stk.top().second;
                flag=1;
                stk.pop();                
            }
            if(flag==1) stk.push({heights[i],last});
            else stk.push({heights[i],i});
            flag=0;            
        }  
        int n = heights.size();
        while(!stk.empty())
        {
            maxi = max(maxi,(n-stk.top().second)*stk.top().first);
            stk.pop();
        }
        return maxi;      
    }
};
