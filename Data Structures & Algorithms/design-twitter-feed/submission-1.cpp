class Twitter {
private:
    unordered_map<int,vector<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int t=0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t,tweetId});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        vector<int> result;
        for(auto& i : tweets[userId])
        {
            pq.push(i);
            if(pq.size()>10) pq.pop();
        }

        for(int i : followers[userId])
        {
            if(i==-1) continue;
            for(auto& i : tweets[i])
            {
                pq.push(i);
                if(pq.size()>10) pq.pop();
            }
        }

        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].push_back(followeeId);        
    }
    
    void unfollow(int followerId, int followeeId) {
        if(folloerId==followeeId) return;
        for(int i=0;i<followers[followerId].size();i++)
        {
            if(followers[followerId][i]==followeeId)
            {
                followers[followerId][i]=-1;
            }
        }
    }
};
