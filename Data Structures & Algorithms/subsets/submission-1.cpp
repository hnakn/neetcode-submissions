class Solution {
public:
    void subs(vector<int>& nums, int index, vector<int> curr, vector<vector<int>>& result)
    {
        result.push_back(curr);
        for(int i = index;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            subs(nums, i+1, curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        subs(nums, 0, {}, result);
        return result;        
    }
};
