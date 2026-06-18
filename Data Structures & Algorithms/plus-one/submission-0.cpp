class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]<9)
            {
                digits[i]++;
                return digits;
            }
            digits[i]=0;
            carry=1;
        }
        digits.insert(digits.begin(),1);
        return digits;
        
    }
};
