class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int count=1,maxi=INT_MAX,target=nums.size()-1;
        for(int i=0;i<target;i++)
        {
            maxi = max(maxi,nums[i]);
            count++;
            if(i+maxi>=target) return count;
            maxi--;
        }
        return count;
    }
};
