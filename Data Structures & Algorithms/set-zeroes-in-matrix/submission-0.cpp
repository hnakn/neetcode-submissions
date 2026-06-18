class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    int ti=i;
                    while(ti>=0)
                    {
                        if(matrix[ti][j]!=0) matrix[ti][j]=-1;
                        ti--;
                    }
                    ti=i;
                    while(ti<m)
                    {
                        if(matrix[ti][j]!=0) matrix[ti][j]=-1;
                        ti++;
                    }
                    int tj=j;
                    while(tj<n)
                    {
                        if(matrix[i][tj]!=0) matrix[i][tj]=-1;
                        tj++;
                    }
                    tj=j;
                    while(tj>=0)
                    {
                        if(matrix[i][tj]!=0) matrix[i][tj]=-1;
                        tj--;
                    }
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==-1) matrix[i][j]=0;
            }
               
        }
    }
};
