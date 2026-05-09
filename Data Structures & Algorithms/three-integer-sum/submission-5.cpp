class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());

        for(int i : nums) mp[i]++;

        vector<vector<int>> result;

        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            mp[nums[i]]--;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int sum = nums[i]+nums[j];
                mp[nums[j]]--;
                
                if(-sum>=nums[j] && mp[-sum]>0) result.push_back({nums[i],nums[j],-sum});
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        return result;
        
    }
};
