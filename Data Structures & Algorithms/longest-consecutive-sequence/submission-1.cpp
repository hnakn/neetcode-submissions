class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> freq;
        int maxi = 0;

        for(int i : nums) freq.insert(i);

        for(int i=0;i<nums.size();i++)
        {
            if(freq.count(nums[i]-1)) continue;
            int count=1,curr=nums[i];
            while(1)
            {
                if(freq.count(curr+1))
                {
                    count++;
                    curr = curr+1;
                }
                else 
                {
                    maxi = max(maxi,count);
                    break;
                }                
            }
        }
        return maxi;
    }
};
