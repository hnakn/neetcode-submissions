class Solution {
public:
    bool dfs(int numCourses, vector<vector<int>>& prerequisites, int index, vector<int> vis)
    {
        if(index>=prerequisites.size()) return true;
        if(vis[index]==1) return false;
        vis[index]=1;
        bool flag = dfs(numCourses, prerequisites, prerequisites[index][1], vis);
        return flag;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        bool flag = true;
        for(auto& p : prerequisites)
        {
            flag = flag && dfs(numCourses, prerequisites, p[0],vis);
        }
        return flag;
    }
};
