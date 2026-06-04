class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int count=0,l=0,r=0;
        while(r<nums.size()-1)
        {
            int maxi = INT_MIN;
            for(int i=l;i<=r;i++)
            {
                maxi = max(maxi,i+nums[i]);
            }
            count++;
            l=r+1;
            r=maxi;
        }
        
        return count;
    }
};
