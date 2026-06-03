class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        for(int i : hand) mp[i]++;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++)
        {
            if(mp[hand[i]]==0) continue;
            for(int j=0;j<groupSize;j++)
            {
                if(mp.count(hand[i]+j)==0) return false;
                mp[hand[i]+j]--;
            }
        }

        return true;
    }
};
