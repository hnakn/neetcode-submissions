class Solution {
public: 
    int sol(vector<int>& nums, int index)
    {
        if(index<0) return 0;
        return max(nums[index]+sol(nums,index-2),sol(nums,index-1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return sol(nums,n-1);
    }
};
