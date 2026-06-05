class Solution {
public:
    int sol(vector<int>& nums, int target, int index, vector<vector<int>>& dp,int curr,int sum)
    {
        if(index==nums.size() && curr==target) return 1;
        else if(index==nums.size()) return 0; 
        if(dp[index][curr+sum]!=-1) return dp[index][curr+sum];
        return dp[index][curr+sum] = sol(nums,target,index+1, dp,curr-nums[index],sum) + sol(nums, target,index+1,dp,curr+nums[index],sum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums) sum += i;
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*sum+1,-1));
        return sol(nums,target,0,dp,0,sum);
    }
};
