class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++)
        {
            v.push_back({position[i],i});
        }
        sort(v.begin(),v.end());

        unordered_set<int> st;        

        for(int i=0;i<position.size();i++)
        {
            int steps = (target-v[i].first)/speed[v[i].second];
            if((target-v[i].first)%speed[v[i].second]!=0) steps++;
            if(i<position.size()-1)
            {
                int next = (target-v[i+1].first)/speed[v[i+1].second];
                if((target-v[i+1].first)%speed[v[i+1].second]!=0) next++;
                if(steps<next)
                {
                    continue;
                }
                else
                {
                    st.insert(steps);
                }
            }
            else
            {
                st.insert(steps);
            }
        }
        return st.size();
        
    }
};
