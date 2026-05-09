class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto& x : mp) pq.push({x.second,x.first});
        int i=0;
        vector<int> sol;
        while(i<k)
        {
            sol.push_back(pq.top().second);
            pq.pop();
            i++;
        }     
        return sol;   
    }
};
