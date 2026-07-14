class Solution {
public:
    int reverse(int x) {
        int result=0;
        while(x!=0)
        {
            int curr = x%10;
            if(result> INT_MAX/10 || (result==INT_MAX/10 && curr>7)) return 0;
            if(result< INT_MIN/10 || (result==INT_MIN && curr<-8)) return 0;
            result = result*10 + curr;          
            
            x /= 10;
        }
        return result;

    }
};
