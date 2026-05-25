class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c : tasks)
        {
            freq[c-'A']++;
        }       

        priority_queue<int> pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                pq.push(freq[i]);
            }
        } 
        int t = 0;
        queue<pair<int,int>> q;
        while(!pq.empty() || !q.empty())
        {
            if(!q.empty() && q.front().second==t) 
            {
                pq.push(q.front().first);
                q.pop();
            }

            if(pq.empty())
            {
                t++;
                continue;
            }
            if(pq.top()>1) q.push({pq.top()-1,t+n+1});
            pq.pop();
            t++;
            
        }
        return t;
    }
};
