class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l=0,r=m-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(matrix[mid][0]>target) 
            {
                r=mid-1;
                continue;
            }
            else if(matrix[mid][n-1]<target) 
            {
                l=mid+1;
                continue;
            }

            int a = 0,b=n-1;
            while(a<=b)
            {
                int m = (a+b)/2;
                if(matrix[mid][m]==target) return true;
                else if(matrix[mid][m]<target) a=m+1;
                else b=m-1;
            }
            return false;
        }  
        return false;      
    }
};
