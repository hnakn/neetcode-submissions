class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, l=0,r=0,maxi=INT_MIN;

        while(r<nums.size())
        {
            sum+=nums[r];
            r++;
            maxi = max(sum,maxi);
            if(sum<0)
            {
                sum=0;
                l=r;
            }
        }
        return maxi;
    }
};
