class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c : tasks) freq[c-'A']++;
        priority_queue<pair<int,pair<char,int>>> pq;
        for(char c : tasks)
        {
            pq.push({freq[c-'A'], {c, 0}});
        }

        int t=0;
        while(!pq.empty())
        {
            if(pq.top().second.second>=t)
            {
                pair<int,pair<char,int>> temp = pq.top();
                pq.pop();
                pq.push({temp.first-1,{temp.second.first, temp.second.second+n+1}});
            }
            t++;
        }
        return t;
        
    }
};
