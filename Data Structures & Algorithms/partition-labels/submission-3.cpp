class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,-1);
        for(int i=0;i<s.size();i++) freq[s[i]-'a']=max(i,freq[s[i]-'a']);
        vector<int> result;
        int l=0,r=0,x=0;
        while(r<s.size())
        {
            x = max(x,freq[s[r]-'a']);
            if(x==r) 
            {
                result.push_back(r-l+1);
                l=r+1;
            }
            
            r++;            
        }
        return result;
    }
};
