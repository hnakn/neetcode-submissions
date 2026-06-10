class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        for(auto& it : triplets)
        {
            if(it[0]>target[0] || it[1]>target[1] || it[2]>target[2]) it = {-1,-1,-1};
        }

        vector<int> res(3,0);
        for(auto& it : triplets)
        {
            if(it[0]==target[0]) res[0]=1;
            if(it[1]==target[1]) res[1]=1;
            if(it[2]==target[2]) res[2]=1;
        }

        for(int i : res) if(i==0) return false;
        return true;
    }
};
