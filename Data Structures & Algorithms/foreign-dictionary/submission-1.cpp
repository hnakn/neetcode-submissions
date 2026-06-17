class Solution {
public:
    string result;
    bool flag = false;
    void topo(unordered_map<char,vector<char>>& mp, vector<int>& vis, char curr)
    {
        if(vis[curr-'a']==1) 
        {
            flag=true;
            return;
        }
        if(vis[curr-'a']==2) return;
        vis[curr-'a']=1;
        for(char c : mp[curr])
        {
            topo(mp,vis,c);
        }
        vis[curr-'a']=2;
        result.push_back(curr);
    }

    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> mp;

        for(int i=0;i<words.size()-1;i++)
        {
            string a = words[i],b = words[i+1];
            int j=0;
            while(j<a.size() && j<b.size())
            {
                if(a[j]==b[j])
                {
                    j++;
                    continue;
                }
                mp[a[j]].push_back(b[j]);
                j=-1;
                break;
            }
            if(j!=-1 && a.size()>b.size()) return "";
        }

        vector<int> vis(26,0);
        for(string s : words)
        {
            for(char c : s)
            {
                topo(mp,vis,c);
            }
        }
        if(flag) return "";
        reverse(result.begin(),result.end());
        return result;
    }
};
