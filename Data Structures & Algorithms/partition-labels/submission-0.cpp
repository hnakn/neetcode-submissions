class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        for(char c : s) freq[c-'a']++;
        unordered_set<char> st;
        vector<int> result;
        int l=0,r=0;
        while(r<s.size())
        {
            st.insert(s[r]);
            freq[s[r]-'a']--;
            if(freq[s[r]-'a']==0) st.erase(s[r]);
            r++;
            if(st.empty())
            {
                result.push_back(r-l);
                l=r;
            }
            
        }
        return result;
    }
};
