class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs) 
        {
            string temp = s;
            sort(s.begin(),s.end());
            mp[s].push_back(temp);
        }  
        vector<vector<string>> sol;
        for(auto& it:mp)
        {
            sol.push_back(it.second);
        }   
        return sol;   
    }
};
