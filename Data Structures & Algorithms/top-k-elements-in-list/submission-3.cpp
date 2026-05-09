class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums) mp[i]++;
        
        vector<vector<int>> freq(nums.size()+1);

        for(auto& it : mp)
        {
            freq[it.second].push_back(it.first);
        }   

        vector<int> result;

        for(int i=nums.size();i>=0;i--)
        {
            if(freq[i].empty()) continue;
            for(int j : freq[i])
            {
                result.push_back(j);
                if(result.size()==k) return result;
            }            
        }
        return result;
    }
};
