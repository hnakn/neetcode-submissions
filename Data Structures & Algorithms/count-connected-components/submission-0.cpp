class Solution {
public:
    void dfs(int index, vector<int>& vis,unordered_map<int,vector<int>>& mp)
    {
        if(vis[index]==1) return;
        vis[index]=1;
        for(int i : mp[index]) dfs(i,vis,mp);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        unordered_map<int, vector<int>> mp;
        int count=0;
        for(auto& it : edges)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++)
        {
            if(vis[i]==1) continue;
            count++;
            dfs(i,vis,mp);
        }
        return count;
    }
};
