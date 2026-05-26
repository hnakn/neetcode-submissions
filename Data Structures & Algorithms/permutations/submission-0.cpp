class Solution {
public:
    void bt(vector<int>& nums, vector<bool> used, vector<int> curr, vector<vector<int>>& result)
    {
        if(curr.size()==nums.size()) 
        {
            result.push_back(curr);
            return;
        }

        for(int i = 0; i<nums.size();i++)
        {
            if(used[i]) continue;
            curr.push_back(nums[i]);
            used[i]=true;
            bt(nums,used,curr,result);
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(),false);
        bt(nums,used,{},result);
        return result;
    }
};
