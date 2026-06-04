class Solution {
public:
    bool checkValidString(string s) {
        int open=0,close=0,star=0;
        for(char c : s)
        {
            if(c=='(') open++;
            else if(c==')') 
            {
                if(open==0) return false;
                else open--;
            }
            else star++;
        }
        if(open-star>0) return false;
        return true;
    }
};
