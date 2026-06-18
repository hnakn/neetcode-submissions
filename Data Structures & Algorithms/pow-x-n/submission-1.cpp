class Solution {
public:
    double myPow(double x, int n) {
        double temp = x;
        bool flag = false;
        if(n<0)
        {
            flag=true;
            n *= -1;
        }
        for(int i=0;i<n-1;i++)
        {
            temp *= x;
        }
        if(flag) return 1/temp;
        else if(n==0) return 1.0;
        return temp;
    }
};
