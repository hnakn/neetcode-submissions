class Solution {
public:
    bool bt(vector<vector<char>>& board, string word,int curr, int i, int j,vector<vector<int>>& vis)
    {
        if(curr==word.size()) return true;
        if(i>=board.size() || j>=board[0].size() || curr>word.size() || i<0 || j<0 || board[i][j]!=word[curr]) return false;
        if(vis[i][j]==1) return false;
        vis[i][j]=1;
        bool fc = bt(board,word,curr+1,i+1,j,vis);
        bool bc = bt(board,word,curr+1,i-1,j,vis);
        bool lc = bt(board,word,curr+1,i,j-1,vis);
        bool rc = bt(board,word,curr+1,i,j+1,vis);
        vis[i][j] = 0;
        return fc || bc || lc || rc;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(bt(board, word, 0, i, j,vis)) return true;
            }
        }
        return false;
    }
};
