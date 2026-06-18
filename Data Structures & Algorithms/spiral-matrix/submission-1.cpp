class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l=0,r=matrix[0].size()-1,t=0,b=matrix.size()-1;

        vector<int> result;
        while(l<=r && t<=b)
        {
            int i=t,j=l;
            for(j=l;j<=r;j++)
            {
                result.push_back(matrix[t][j]);
            }
            t++;
            for(i=t;i<=b;i++)
            {
                result.push_back(matrix[i][r]);
            }
            r--;

            if(t<=b)
            {
            for(j=r;j>=l;j--)
            {
                result.push_back(matrix[b][j]);
            }
            b--;
            }
            if(l<=r)
            {
            for(i=b;i>=t;i--)
            {
                result.push_back(matrix[i][l]);
            }
            l++;
            }            
        }
        return result;
    }
};
