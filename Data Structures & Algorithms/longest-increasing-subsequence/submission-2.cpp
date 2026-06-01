class Solution {
public:
    int sol(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index<=0) return 1;
        if(dp[index]!=-1) return dp[index];
        int count = 0;
        for(int i=index-1;i>=0;i--)
        {
            if(nums[index]>nums[i]) count = max(count,sol(nums,i,dp));
        }
        return dp[index] = 1+count;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int result=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            result = max(result, sol(nums,i,dp));
        }
        return result;
    }
};
