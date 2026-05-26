class Solution {
public:
    void bt(vector<int>& nums,int index, int target, vector<int> curr, vector<vector<int>>& result, int sum)
    {
        if(index>=nums.size() || sum>target) return;
        if(sum==target)
        {
            result.push_back(curr);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            bt(nums,i, target, curr, result, sum+nums[i]);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        bt(nums,0, target, {}, result, 0);
        return result;
    }
};
