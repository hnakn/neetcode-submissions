class Solution {
public:
    bool sol(vector<int>& nums, int index, int sum, int curr)
    {
        if(curr==sum) return true;
        if(index==nums.size() || curr>sum) return false;
        return sol(nums,index+1,sum,curr) || sol(nums,index+1,sum,curr+nums[index]);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i: nums) sum+=i;
        if(sum%2!=0) return false;
        return sol(nums,0,sum/2,0);
    }
};
