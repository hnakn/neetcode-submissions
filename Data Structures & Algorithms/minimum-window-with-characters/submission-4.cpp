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

        int l=0,r=0;
        string result = s;
        unordered_map<char,int> freq;

        while(r<s.size())
        {
            freq[s[r]]++;
            if(mp.count(s[r]) && freq[s[r]]<=mp[s[r]]) count++;
            while(l<=r && (!mp.count(s[l]) || freq[s[l]]>mp[s[l]]))
            {
                freq[s[l]]--;
                if(mp.count(s[l]) && freq[s[l]]<mp[s[l]]) count--;
                l++;
            }
            if(r-l+1<result.size() && count>=t.size()) result = s.substr(l,r-l+1);
            r++;
        }
        return result;
    }
};
