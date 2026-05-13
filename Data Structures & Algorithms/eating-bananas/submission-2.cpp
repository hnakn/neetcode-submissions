class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(int i:piles) maxi = max(maxi,i);
        int l=1,r=maxi,result=maxi;
        while(l<=r)
        {
            int mid = (l+r)/2,hrs=0;            
            for(int i:piles)
            {
                hrs += (i+mid-1)/mid;
            }
            if(hrs<=h){
                result = min(result,mid);
                r=mid-1;
            }
            else if(hrs>h) l=mid+1;
            
        }    
        return result;    
    }
};
