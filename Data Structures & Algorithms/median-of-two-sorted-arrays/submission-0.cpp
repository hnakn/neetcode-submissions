class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int m=nums1.size(),n=nums2.size(); 
        int total=m+n;
        int mid = (total+1)/2;
        int l=0,r=m,part;
        while(l<=r)
        {
            int mid1 = (l+r)/2;
            int mid2 = mid-mid1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<m) r1=nums1[mid1];
            if(mid2<n) r2=nums2[mid2];
            if(mid1>0) l1=nums1[mid1-1];
            if(mid2>0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1) 
            {
                if(total%2==0)
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else return max(l1,l2);
            }
            else if(l1>r2) r=mid1-1;
            else l=mid1+1;
        }
        

    }
};
