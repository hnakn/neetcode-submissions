class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(),suffix=-1,prefix=-1;
        vector<int> suff(n),pref(n);

        for(int i=0;i<n;i++)
        {
            pref[i]=prefix;
            prefix=max(height[i],prefix);
        }

        for(int i=n-1;i>=0;i--)
        {
            suff[i]=suffix;
            suffix=max(height[i],suffix);
        }

        int maxi=0;

        for(int i=0;i<n;i++)
        {
            if(pref[i]==-1 || suff[i]==-1) continue;

            int capacity = min(suff[i],pref[i]);

            if(capacity<=height[i]) continue;

            maxi += capacity-height[i];
        }

        return maxi;

    }
};
