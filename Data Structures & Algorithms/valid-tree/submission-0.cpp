class Solution {
public:
    int count = 0;
    bool dfs(int index, vector<int>& vis,unordered_map<int,vector<int>>& mp)
    {
        if(vis[index]==1) return false;
        vis[index]=1;
        count++;
        bool flag = true;
        for(int i : mp[index]) flag = flag && dfs(i,vis,mp);
        return flag;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        unordered_map<int, vector<int>> mp;
        for(auto& it : edges)
        {
            mp[it[0]].push_back(it[1]);
        }

        if(dfs(0,vis,mp) && count==n) return true;        
        return false;
    }
};
