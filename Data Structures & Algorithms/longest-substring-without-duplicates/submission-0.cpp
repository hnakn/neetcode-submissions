class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int result=0,l=0,r=0;

        while(r<s.size())
        {
            mp[s[r]]++;
            while(mp[s[r]]>1)
            {
                mp[s[l]]--;
                l++;
            }
            result = max(result,r-l+1);
            r++;
        }
        return result;
        
        
    }
};
