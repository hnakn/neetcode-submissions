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

            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                if(l>i+1 && nums[l]==nums[l-1]) l++;
                else if(r<nums.size()-1 && nums[r]==nums[r+1]) r--;
                else if(nums[l]+nums[r]+nums[i]>0) r--;
                else if(nums[l]+nums[r]+nums[i]<0) l++;
                else
                {
                    result.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
            }
        }
       
        return result;
        
    }
};
