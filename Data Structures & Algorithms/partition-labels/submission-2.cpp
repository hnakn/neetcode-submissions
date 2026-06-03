
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        for(char c : s) freq[c-'a']++;

        vector<int> result;
        int active = 0, l = 0;

        for(int r = 0; r < s.size(); r++)
        {
            if(freq[s[r]-'a'] == 1) active++; // last occurrence starting
            freq[s[r]-'a']--;

            if(freq[s[r]-'a'] == 0) active--; // character finished

            if(active == 0)
            {
                result.push_back(r - l + 1);
                l = r + 1;
            }
        }

        return result;
    }
};
