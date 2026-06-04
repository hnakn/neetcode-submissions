class Solution {
public:
    bool checkValidString(string s) {
        int lmax=0,lmin=0;
        for(char c : s)
        {
            if(c=='(') 
            {
                lmax++;
                lmin++;
            }
            else if(c==')') 
            {
                lmax--;
                lmin--;
            }
            else 
            {
                lmax++;
                lmin--;
            }
            if(lmin<0) lmin=0;
            if(lmax<0) return false;
        }
        
        if(lmin==0) return true;
        else return false;
    }
};
