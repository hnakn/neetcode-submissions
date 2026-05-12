class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++)
        {
            v.push_back({position[i],i});
        }
        sort(v.begin(),v.end());
        stack<float> stk;
        for(int i=v.size()-1;i>=0;i--)
        {
            float steps = (target-v[i].first)/(float)speed[v[i].second];
            cout << steps;
            if(stk.empty() || stk.top()<steps) stk.push(steps);
        }
        return stk.size();
    }
};
