class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        for(int i=0;i<s.size();i++)
        {
            int l=i,r=i;
            bool flag = true;
            while(l>=0 && r<s.size())
            {
                if(s[l--]!=s[r++]) flag=false;
            }
            if(flag) count++;


            l=i,r=i+1;
            flag = true;
            while(l>=0 && r<s.size())
            {
                if(s[l--]!=s[r++]) flag=false;
            }
            if(flag) count++;
        }


        return count;
    }
};
