class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        for(int i : hand) mp[i]++;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++)
        {
            if(mp[hand[i]]==0) continue;
            int count = 0,j=i;
            while(count<groupSize)
            {
                if(j==hand.size()) return false;
                if(mp[hand[j]]==0)
                {
                    j++;
                }
                count++;
                mp[j]--;
            }
        }
        return true;
    }
};
