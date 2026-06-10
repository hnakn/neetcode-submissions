class Solution {
public:
    int sol(vector<int>& nums, int left, int right, vector<vector<int>>& dp)
    {
        if(left==0 || right==nums.size()-1 || left>right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int result = 0;
        for(int i=left;i<=right;i++)
        {
            result = max(result, nums[left-1]*nums[i]*nums[right+1] + sol(nums,i+1,right,dp) + sol(nums,left,i-1,dp));
        }
        return dp[left][right]=result;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return sol(nums,1,nums.size()-2,dp);
    }
};
