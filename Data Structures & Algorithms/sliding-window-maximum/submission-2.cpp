class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;
        int i = 0;
        while(i<k)
        {
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        result.push_back(nums[dq.front()]);

        while(i<n)
        {
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i-dq.front()>=k) dq.pop_front();
            result.push_back(nums[dq.front()]);
            i++;
        }

        return result;
    }
};
