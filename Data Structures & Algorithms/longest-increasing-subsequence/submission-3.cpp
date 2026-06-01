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
        vector<int> dp(nums.size(),0);
        int result=1;
        dp[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            int count=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j]) count =  max(count,dp[j]);
            }
            dp[i]=count+1;
        }
        return dp[nums.size()-1];
    }
};
