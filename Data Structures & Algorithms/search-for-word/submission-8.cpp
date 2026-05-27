class Solution {
public:
    bool bt(vector<vector<char>>& board, string word,int curr, int i, int j)
    {
        if(curr==word.size()) return true;
        if(i>=board.size() || j>=board[0].size() || curr>word.size() || i<0 || j<0 || board[i][j]!=word[curr]) return false;
        if(board[i][j]=='#') return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool fc = bt(board,word,curr+1,i+1,j);
        bool bc = bt(board,word,curr+1,i-1,j);
        bool lc = bt(board,word,curr+1,i,j-1);
        bool rc = bt(board,word,curr+1,i,j+1);
        board[i][j] = temp;
        return fc || bc || lc || rc;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0] && bt(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
