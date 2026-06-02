class Solution {
public:
    int result = INT_MAX;
    void sol(string curr, string& endWord, unordered_map<string,int>& mp, int count)
    {
        if(curr==endWord) 
        {
            result = min(result,count);
            return;
        }
        for(int i=0;i<curr.size();i++)
        {
            char temp = curr[i];
            for(int j=0;j<26;j++)
            {
                curr[i]='a'+j;
                if(mp.count(curr) && mp[curr]>0)
                {
                    mp[curr]=0;
                    sol(curr,endWord,mp,count+1);
                    mp[curr]=1;
                }
                curr[i]=temp;
            }
        }

    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(string s : wordList) mp[s]=1;
        sol(beginWord,endWord,mp,1);
        if(result==INT_MAX) return 0;
        return result;
    }
};
