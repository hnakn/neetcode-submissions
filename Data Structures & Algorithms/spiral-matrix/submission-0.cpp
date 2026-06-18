class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l=0,r=matrix[0].size()-1,t=0,b=matrix.size()-1;

        vector<int> result;
        while(l<r && t<b)
        {
            int i=t,j=l;
            while(j<r)
            {
                result.push_back(matrix[i][j]);
                j++;
            }
            while(i<b)
            {
                result.push_back(matrix[i][j]);
                i++;
            }
            while(j>0)
            {
                result.push_back(matrix[i][j]);
                j--;
            }
            while(i>0)
            {
                result.push_back(matrix[i][j]);
                i--;
            }
            l++;
            r--;
            t++;
            b--;
        }
        return result;
    }
};
