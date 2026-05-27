class Solution {
public:
    int dp(int index)
    {
        if(index==0) return 1;
        if(index<0) return 0;
        return dp(index-1)+dp(index-2);
    }

    int climbStairs(int n) {
        return dp(n);
    }
};
