class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n+1);
        for(int i=0;i<=n;i++)
        {
            int count = 0,x=i;
            while(x!=0)
            {
                count++;
                x = x&(x-1);
            }
            output[i]= count;
        }
        return output;
    }
};
