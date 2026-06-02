class Solution {
public:
    int inf = INT_MAX;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) q.push({{i,j},0});
            }
        }

        while(!q.empty())
        {
            int size=q.size();
            for(int a=0;a<size;a++)
            {
                int i=q.front().first.first;
                int j=q.front().first.second;
                int level = q.front().second;
                q.pop();
                if(grid[i][j]==inf) grid[i][j]=level;
                if(i<m-1 && grid[i+1][j]==inf) q.push({{i+1,j},level+1});
                if(i>0 && grid[i-1][j]==inf) q.push({{i-1,j},level+1});
                if(j<n-1 && grid[i][j+1]==inf) q.push({{i,j+1},level+1});
                if(j>0 && grid[i][j-1]==inf) q.push({{i,j-1},level+1});
            }
            
        }
    }
};
