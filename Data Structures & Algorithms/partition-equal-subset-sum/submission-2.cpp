class Solution {
public:
    bool sol(vector<int>& nums, int index, int sum, int curr, vector<vector<int>>& dp)
    {
        if(curr==sum) return true;
        if(index==nums.size() || curr>sum) return false;
        if(dp[index][curr]!=-1) return dp[index][curr];
        return dp[index][curr] = sol(nums,index+1,sum,curr,dp) || sol(nums,index+1,sum,curr+nums[index],dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i: nums) sum+=i;
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1,-1));
        return sol(nums,0,sum/2,0,dp);
    }
};
