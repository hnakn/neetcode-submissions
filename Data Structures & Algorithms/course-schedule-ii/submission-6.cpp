class Solution {
public:
    vector<int> result;
    bool dfs(int index, vector<int>& vis, unordered_map<int,vector<int>>& mp)
    {
        if(vis[index]==1) return false;
        
        if(mp.count(index) && mp[index].size() == 1 && mp[index][0] == -1)
            return true;

        if(mp.count(index)==0) 
        {
            result.push_back(index);
            return true;
        }
        vis[index]=1;
        bool flag = true;
        for(int i : mp[index]) flag=flag && dfs(i, vis, mp);
        if(!flag) return flag;
        vis[index]=0;
        mp[index]={-1};        
        result.push_back(index);
        return flag;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        bool flag = true;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<prerequisites.size();i++)
        {
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!dfs(i,vis, mp)) return {};
        }
        return result;
    }
};
