class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        for(int i=0;i<nums.size();i++) 
        {
            sum = sum^i;
            sum = sum^nums[i];
        }
        
        return sum;
    }
};
