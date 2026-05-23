class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l=0,r=0,maxi=0,result=0;

        while(r<s.size())
        {
            mp[s[r]]++;
            if(mp[s[r]]>maxi) maxi = mp[s[r]];
            while((r-l+1-maxi>k))
            {
                mp[s[l]]--;
                l++;
            }
            result = max(r-l+1,result);
            r++;
        }    
        return result;
    }
};
