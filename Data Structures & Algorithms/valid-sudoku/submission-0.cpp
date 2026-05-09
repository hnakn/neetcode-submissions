class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size(),n = board[0].size();
        int root = sqrt(m);
        vector<unordered_set<char>> rows(m),cols(n);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.') continue;
                if(rows[i].find(board[i][j])!=rows[i].end()) return false;
                else rows[i].insert(board[i][j]);
                if(cols[j].find(board[i][j])!=cols[j].end()) return false;
                else cols[j].insert(board[i][j]);
            }            
        }
        
        vector<vector<unordered_set<char>>> box(m,vector<unordered_set<char>>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.') continue;
                int a = i/root,b=j/root;
                if(box[a][b].find(board[i][j])!=box[i][j].end()) return false;
                else box[a][b].insert(board[i][j]);
            }            
        }

        return true;
    }
};
