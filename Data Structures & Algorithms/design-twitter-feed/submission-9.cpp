class Twitter {
private:
    unordered_map<int,unordered_set<int>> followers;
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
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result;
        for(auto& i : tweets[userId])
        {
            pq.push(i);
            if(pq.size()>10) pq.pop();
        }

        for(int i : followers[userId])
        {
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
        reverse(result.begin(), result.end());
        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        if(find(followers[followerId].begin(),followers[followerId].end(),followeeId)==followers[followerId].end()) followers[followerId].insert(followeeId);        
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        followers[followerId].erase(followeeId);
    }
};
