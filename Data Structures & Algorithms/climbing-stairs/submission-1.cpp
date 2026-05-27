class Solution {
public:
    int dp(int index,vector<int>& d)
    {
        if(index==0) return 1;
        if(index<0) return 0;
        if(d[index]!=-1) return d[index];
        return d[index] = dp(index-1,d)+dp(index-2,d);
    }

    int climbStairs(int n) {
        vector<int> d(n+1,-1);
        return dp(n,d);
    }
};
