class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        int n1=n,n2=n;
        while(1)
        {
            int slow = 0,fast = 0;
            while(n1>0)
            {
                slow += (n1%10)*(n1%10);
                n1 /= 10;
            }
            while(n2>0)
            {
                fast += (n2%10)*(n2%10);
                n2 /= 10;
            }
            n2=fast;
            fast=0;
            while(n2>0)
            {
                fast += (n2%10)*(n2%10);
                n2 /= 10;
            }
            
            if(slow==1) return true;
            n1=slow;
            n2=fast;
            if(n1==n2) return false;
        }
        return false;
    }
};
