class Solution {
public:
    bool bt(vector<vector<char>>& board, string word, string curr, int i, int j)
    {
        if(curr==word) return true;
        if(i>=board.size() || j>=board[0].size()) return false;
        return bt(board,word,curr+board[i][j],i,j+1) || bt(board,word,curr+board[i][j],i+1,j);
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(bt(board, word, "", i, j)) return true;
            }
        }
        return false;
    }
};
