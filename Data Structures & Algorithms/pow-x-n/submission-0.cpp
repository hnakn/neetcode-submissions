class Solution {
public:
    double myPow(double x, int n) {
        double temp = x;
        for(int i=0;i<abs(n)-1;i++)
        {
            temp *= x;
        }
        if(n<0) return 1/temp;
        else if(n==0) return 1.0;
        return temp;
    }
};
