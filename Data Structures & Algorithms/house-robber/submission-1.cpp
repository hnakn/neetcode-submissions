class Solution {
public: 
    int sol(vector<int>& nums, int index,vector<int>& dp)
    {
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        return dp[index] = max(nums[index]+sol(nums,index-2,dp),sol(nums,index-1,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return sol(nums,n-1,dp);
    }
};
