class Solution {
public:
    bool dfs(int index, vector<int> vis, unordered_map<int,int>& mp)
    {
        if(mp.count(index)==0) return true;
        if(vis[index]==1) return false;
        vis[index]=1;
        bool flag = dfs(mp[index], vis, mp);
        return flag;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        bool flag = true;
        unordered_map<int,int> mp;
        for(int i=0;i<prerequisites.size();i++)
        {
            mp[prerequisites[i][0]] = prerequisites[i][1];
        }
        for(auto& p : prerequisites)
        {
            flag = flag && dfs(p[0],vis, mp);
        }
        return flag;
    }
};
