class Solution {
public:
    bool pali(string s)
    {
        if(s.empty()) return false;
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void bt(string s, vector<string> curr, int index, vector<vector<string>>& result)
    {
        if(index>=s.size()) 
        {
            result.push_back(curr);
            return;
        }
        for(int i=0;i<=s.size()-index;i++)
        {
            if(pali(s.substr(index,i)))
            {
                curr.push_back(s.substr(index,i));
                bt(s,curr,index+i,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        bt(s,{},0,result);        
        return result;
    }
};
