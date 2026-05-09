class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=INT_MIN,l=0,r=heights.size()-1;

        while(l<r)
        {
            int high = min(heights[l],heights[r]);
            int capacity = high*(r-l);
            maxi = max(maxi,capacity);

            if(heights[l]<heights[r]) l++;
            else if(heights[l]>heights[r]) r--;
            else l++;
        }

        return maxi;
        
    }
};
