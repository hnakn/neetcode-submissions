class Solution {
public:
    

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int a=1,b=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=a+b;
            a=b;
            b=dp[i];
        }
        return dp[n];
    }
};
