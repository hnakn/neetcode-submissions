class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], l=1,r=1,maxi=INT_MIN;

        while(r<nums.size())
        {
            sum+=nums[r];
            r++;
            if(sum<0)
            {
                sum=0;
                l=r;
            }
            maxi = max(sum,maxi);
        }
        return maxi;
    }
};
