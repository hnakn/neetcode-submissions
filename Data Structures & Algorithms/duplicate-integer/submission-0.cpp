class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> mp;
        for(int i:nums)
        {
            if(mp.find(i)!=mp.end()) return true;
            mp.insert(i);
        }
        return false;
    }
};