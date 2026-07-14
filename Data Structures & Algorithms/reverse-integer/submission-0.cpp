class Solution {
public:
    int reverse(int x) {
        int result=0;
        while(x!=0)
        {
            int curr = x%10;
            if(result> INT_MAX/10 || (result==INT_MAX && curr>7)) return 0;
            result = result*10 + curr;          
            
            x /= 10;
        }
        return result;

    }
};
