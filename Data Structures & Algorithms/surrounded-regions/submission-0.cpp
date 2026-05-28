class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, int m, int n, vector<vector<int>> vis)
    {
        if(i==0 || j==0 || i==m-1 || j==n-1) return true;
        bool left=false,right=false,top=false,bottom=false;
        if(vis[i][j]==1) return false;
        vis[i][j]=1;
        if(i>0 && board[i-1][j]=='X') left = dfs(board,i-1,j,m,n,vis);
        if(j>0 && board[i][j-1]=='X') top = dfs(board,i,j-1,m,n,vis);
        if(i<m-1 && board[i+1][j]=='X') right = dfs(board,i+1,j,m,n,vis);
        if(j<n-1 && board[i][j+1]=='X') bottom = dfs(board,i,j+1,m,n,vis);
        if(left || right || top || bottom) return true;
        else return false;        
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(board[i][j]=='O')
                {
                    if(dfs(board,i,j,m,n,vis)) board[i][j]='A';
                }
            }
        }

        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(board[i][j]=='A')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};
