class Solution {
public:
    int getSum(int a, int b) {
        int carry=0,result=0;

        for(int i=0;i<32;i++)
        {
            int bit1 = (a>>i)&1;
            int bit2 = (b>>i)&1;
            int bit=0;
            if(bit1==bit2)
            {
                if(bit1 && carry)
                {   
                    carry=1;
                    bit=1;
                }
                else if(bit1)
                {
                    carry=1;
                    bit=0;
                }
                else if(carry)
                {
                    carry=0;
                    bit=1;
                }
                else
                {
                    bit=0;
                }
            }

            else
            {
                if(carry)
                {
                    bit=0;
                    carry=1;
                }
                else
                {
                    bit=1;
                }
            }

            result = result | (bit<<i);
        }
        return result;
    }
};
