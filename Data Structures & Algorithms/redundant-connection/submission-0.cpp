class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            vis[edges[i-1][0]]++;
            vis[edges[i-1][1]]++;
        }
        for(int i=n;i>0;i--)
        {
            if(vis[edges[i-1][0]]==2) return edges[i-1];
        }
        return {};
    }
};
