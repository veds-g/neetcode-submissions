class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> twi;
    unordered_map<int, unordered_set<int>> following;
    int idx;
public:
    Twitter() { idx = 0; }
    
    void postTweet(int userId, int tweetId) {
        twi[userId].push_back({idx++, tweetId});
        if (twi[userId].size() > 10) {
            twi[userId].erase(twi[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> keys = {userId};
        for (auto& x : following[userId]) keys.push_back(x);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans;

        for (auto& x : keys) {
            for (auto& y : twi[x]) {
                pq.push(y);
                if (pq.size() > 10) pq.pop();
            }
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].erase(followeeId);
    }
};
