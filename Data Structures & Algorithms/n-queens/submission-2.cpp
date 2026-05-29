class Solution {
public:
    bool issafe(vector<string>& curr, int n,int x, int y)
    {   
        for(int i=x-1;i>=0;i--)
        {
            if(curr[i][y]=='Q') return false;
        }

        int i=x-1,j=y-1;
        while(i>=0 && j>=0)
        {
            if(curr[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=x-1,j=y+1;
        while(i>=0 && j<=n-1)
        {
            if(curr[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }

    void bt(int n, vector<vector<string>>& result, vector<string>& curr, int count)
    {
        if(count==n)
        {

            result.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!issafe(curr,n,count,i)) continue;
            curr[count][i] = 'Q';
            bt(n,result,curr,count+1);
            curr[count][i] = '.';
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string temp = "";
        for(int i=0;i<n;i++)
        {
            temp+=".";
        }
        vector<string> curr;
        for(int i=0;i<n;i++)
        {
            curr.push_back(temp);
        }
        bt(n,result,curr,0);
        return result;
    }
};
