class Solution {
public:
    void bt(vector<int>& nums,int index, int target, vector<int> curr, vector<vector<int>>& result, int sum)
    {
        if(sum==target)
        {
            result.push_back(curr);
            return;
        }
        if(index>=nums.size() || sum>target) return;
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            bt(nums,i+1, target, curr, result, sum+nums[i]);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        bt(candidates,0, target, {}, result, 0);
        return result;
    }
};
