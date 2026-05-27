class Solution {
public:
    bool bt(vector<vector<char>>& board, string word, string curr, int i, int j, bool f, bool b, bool l, bool r)
    {
        if(curr==word) return true;
        if(i>=board.size() || j>=board[0].size() || curr.size()>=word.size()) return false;
        bool fc = !b && bt(board,word,curr+board[i][j],i+1,j, true, false, false,false);
        bool bc = !f && bt(board,word,curr+board[i][j],i-1,j, false, true, false, false);
        bool lc = !r && bt(board,word,curr+board[i][j],i,j-1, false, false, true,false);
        bool rc = !l && bt(board,word,curr+board[i][j],i,j+1, false, false, false, true);
        return fc || bc || lc || rc;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(bt(board, word, "", i, j,false, false, false, false)) return true;
            }
        }
        return false;
    }
};
