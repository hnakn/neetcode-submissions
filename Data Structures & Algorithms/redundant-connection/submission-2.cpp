class Solution {
public:
    pair<int,int> dfs(int index, vector<int>& vis,unordered_map<int,vector<int>>& mp,int par)
    {
        if(vis[index]==1) return {par,index};
        vis[index]=1;
        pair<int,int> res;
        for(int i : mp[index]) 
        {
            if(i!=par) 
            {
                res = dfs(i,vis,mp,index);
                if(res.first!=-1) return res;
            }
        }
        return {-1,-1};
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> mp;
        int count=0;
        for(auto& it : edges)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
            vector<int> vis(n+1,0);
            pair<int,int> result = dfs(it[0],vis,mp,-1);
            if(result.first!=-1) return {it[0],it[1]};
        }
        return {};
    }
};
