class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int suffix=1,prefix=1;
        vector<int> suff(nums.size()),pref(nums.size());

        for(int i=0;i<nums.size();i++)
        {
            pref[i]=prefix;
            prefix *= nums[i];
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            suff[i]=suffix;
            suffix *= nums[i];
        }
        
        vector<int> result(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            result[i]=suff[i]*pref[i];
        }
        return result;
    }
};
