class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(string s : wordList) mp[s]=1;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string curr = q.front().first;
            int t = q.front().second;
            if(curr==endWord) return t;
            q.pop();
            for(int i=0;i<curr.size();i++)
            {
                char temp = curr[i];
                for(int j=0;j<26;j++)
                {
                    curr[i]='a'+j;
                    if(mp.count(curr) && mp[curr]>0)
                    {
                        mp[curr]=0;
                        q.push({curr,t+1});
                    }
                }
                curr[i]=temp;
            }
        }
        return 0;
    }
};
