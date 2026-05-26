class Solution {
public:
    void bt(vector<int>& nums, int index, vector<int> curr, vector<vector<int>>& result)
    {
        result.push_back(curr);
        if(index>=nums.size()) return;

        for(int i = index;i<nums.size();i++)
        {
            if(i>0 && nums[i-1]==nums[i]) continue;
            curr.push_back(nums[i]);
            bt(nums,i+1,curr,result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        bt(nums,0,{},result);
        return result;
    }
};
