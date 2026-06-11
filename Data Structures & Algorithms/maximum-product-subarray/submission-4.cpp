class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprod=1,maxprod=1,result=0;
        for(int i : nums)
        {
            if(i<0)
            {
                swap(maxprod,minprod);
            }
            else if(i==0)
            {
                maxprod=1;
                minprod=1;
            }
            maxprod = max(i,maxprod*i);
            minprod = min(i,minprod*i);
            result = max(result,max(maxprod,minprod));
        }
        return result;
    }
};
