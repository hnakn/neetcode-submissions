class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size()-1;
        int top = left, bottom = right;

        while(left<=right && top<=bottom)
        {
            int len = right-left;
            for(int i=0;i<len;i++)
            {
                int temp = matrix[top][left+i];
                matrix[top][left+i] = matrix[bottom-i][left];
                matrix[bottom-i][left] = matrix[bottom][right-i];
                matrix[bottom][right-i] = matrix[top+i][right];
                matrix[top+i][right] = temp;
            }
            top++;
            right--;
            left++;
            bottom--;
        }
    }
};
