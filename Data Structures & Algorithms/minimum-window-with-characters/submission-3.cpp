class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int count=0;
        unordered_map<char,int> mp;
        for(char c : t)
        {
            mp[c]++;
        }        

        int l=0,r=0,start=0,mini=INT_MAX;
        string result = s;
        unordered_map<char,int> freq;

        while(r<s.size())
        {
            freq[s[r]]++;
            if(mp.count(s[r]) && freq[s[r]]<=mp[s[r]]) count++;
            while(count==t.size())
            {
                if(r-l+1<mini)
                {
                    mini = r-l+1;
                    start = l;
                }
                freq[s[l]]--;
                if(mp.count(s[l]) && freq[s[l]]<mp[s[l]]) count--;
                l++;
            }
            
            r++;
        }
        if(mini == INT_MAX) return "";
        return s.substr(start,mini);
    }
};
