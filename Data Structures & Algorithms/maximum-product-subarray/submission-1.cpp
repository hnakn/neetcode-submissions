class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=1,minprod=1,right=0,maxi=INT_MIN;
        while(right<nums.size())
        {
            if(nums[right]<0)
            {
                maxprod=1;          
            }
            else 
            {
                maxprod *= nums[right];
            }
            minprod *= nums[right];
            if(minprod==0) minprod = maxprod;
            right++;   
            maxi=max(maxi,max(maxprod,minprod));
        }
        return maxi;
    }
};
