class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_set<int> st;
        for(int i=0;i<position.size();i++)
        {
            if((target-position[i])/speed[i]) st.insert((target-position[i])/speed[i]);
            else st.insert(((target-position[i])/speed[i])+1);
        }
        return st.size();
        
    }
};
