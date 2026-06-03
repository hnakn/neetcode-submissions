class Solution {
public:
    vector<int> result;
    bool dfs(int index, vector<int>& vis, unordered_map<int,vector<int>>& mp)
    {
        if(vis[index]==1) return false;
        if(vis[index]==2) return true;
        
        if(mp.count(index)==0) 
        {
            result.push_back(index);
            return true;
        }
        vis[index]=1;
        
        for(int i : mp[index]) if(!dfs(i, vis, mp)) return false;
    
        vis[index]=2;
             
        result.push_back(index);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
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
