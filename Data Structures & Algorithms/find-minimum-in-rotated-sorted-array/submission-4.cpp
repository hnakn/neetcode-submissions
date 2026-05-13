class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            if(l==r) return nums[l];
            int mid = (l+r)/2;
            if(nums[mid]<=nums[l] && nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]) return nums[mid];
            else if(nums[mid]<nums[l] || nums[l]>nums[r]) l=mid+1;
            else r = mid-1;
        }  
        return -1;      
    }
};
