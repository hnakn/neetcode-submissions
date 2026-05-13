class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1,n=nums.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if((mid==n || nums[mid]<nums[mid+1]) && (mid==0 || nums[mid]<nums[mid-1])) return nums[mid];
            else if(nums[mid]>=nums[l]) l=mid+1;
            else r=mid-1;
        }  
        return -1;      
    }
};
