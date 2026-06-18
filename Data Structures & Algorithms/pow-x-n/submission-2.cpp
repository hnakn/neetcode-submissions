class Solution {
public:
    double sol(double x, int n)
    {
        if(n==0) return 1;
        double result = sol(x,n/2);
        result = result*result;
        if(n%2==0) return result;
        else return x*result;
    }
    double myPow(double x, int n) {
        double result = sol(x,n);
        if(n<0) return 1/result;
        return result;        
    }
};
