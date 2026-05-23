class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        for(char c :s1 )
        {   
            mp[c]++;
        }     

        unordered_map<char,int> freq;
        int l=0,r=0;
        while(r<s2.size())
        {
            freq[s2[r]]++;
            if(r-l+1>s1.size())
            {
                freq[s2[l]]--;
                if(freq[s2[l]]==0) freq.erase(s2[l]);
                l++;
            }
            if(freq==mp) return true;
            r++;
        }           
        return false;
    }
};
