class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size(),n = board[0].size();
        int root = sqrt(m);
        vector<int> rows(m,0),cols(n,0);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.') continue;

                int val = board[i][j]-'0';
                int digit = val-1;
                int mask = 1<<digit;

                if(rows[i]&mask || cols[j]&mask) return false;
                
                rows[i] |= mask;
                cols[j] |= mask;
            }
        }

        vector<vector<int>> boxes(root,vector<int>(root,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.') continue;

                int a=i/3,b=j/3;

                int val = board[i][j]-'0';
                int digit = val-1;
                int mask = 1<<digit;

                if(boxes[a][b]&mask) return false;
                
                boxes[a][b] |= mask;                            
            }
        }
        return true;
    }
};
