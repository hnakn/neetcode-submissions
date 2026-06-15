struct TrieNode {
    unordered_map<char,TrieNode*> mp;
    bool end;
    TrieNode()
    {
        this->end = false;
    }
};

class Solution {
public:
    vector<string> result;
    void sol(vector<vector<char>>& board, TrieNode* root, string curr, int i, int j, int m, int n, vector<vector<int>>& vis)
    {
        if(root->end) 
        {
            result.push_back(curr);
            root->end = false;
        }
        if(i==m || j==n || i<0 || j<0 || vis[i][j]==1) return;
        if(root->mp.count(board[i][j])==0) return;
        vis[i][j]=1;
        sol(board,root->mp[board[i][j]],curr+board[i][j],i+1,j,m,n,vis);
        sol(board,root->mp[board[i][j]],curr+board[i][j],i,j+1,m,n,vis);
        sol(board,root->mp[board[i][j]],curr+board[i][j],i-1,j,m,n,vis);
        sol(board,root->mp[board[i][j]],curr+board[i][j],i,j-1,m,n,vis);
        vis[i][j]=0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string s : words)
        {
            TrieNode* temp = root;
            for(char c : s)
            {
                if(temp->mp.count(c)==0) temp->mp[c] = new TrieNode();
                temp = temp->mp[c];
            }
            temp->end = true;
        }
        int m=board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sol(board,root,"",i,j,m,n,vis);
            }
        }
        return result;
    }
};
