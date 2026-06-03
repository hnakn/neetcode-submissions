class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        for(char c : s) freq[c-'a']++;
        vector<int> result;
        int l=0,r=0,x=0;
        while(r<s.size())
        {
            if(freq[s[r]-'a']==1) x++;
            freq[s[r]-'a']--;
            if(freq[s[r]-'a']==0) 
            {
                x--;
            }
            r++;
            if(x==0)
            {
                result.push_back(r-l);
                l=r;
            }
            
        }
        return result;
    }
};
