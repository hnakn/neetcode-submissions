class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1,leftmax=height[0],rightmax=height[n-1],result=0,maxi=0;

        while(l<r)
        {
            if(leftmax<rightmax)
            {
                l++;
                result = leftmax-height[l];
                leftmax = max(leftmax,height[l]);
                if(result<=0) continue;
                else maxi+=result;
                cout << result;
            }
            else
            {
                r--;
                result = rightmax-height[r];
                rightmax = max(rightmax,height[r]);
                if(result<=0) continue;
                else maxi+=result;
                cout << result;
            }
        }
        return maxi;

    }
};
