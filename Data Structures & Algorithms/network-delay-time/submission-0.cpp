class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edgeMap;

        for(auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            edgeMap[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [wt, node] = pq.top(); pq.pop();
            if (wt > dist[node]) continue;

            for (auto& nei : edgeMap[node]) {
                auto [next, w] = nei;
                if (dist[next] > dist[node] + w) {
                    dist[next] = dist[node] + w;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
