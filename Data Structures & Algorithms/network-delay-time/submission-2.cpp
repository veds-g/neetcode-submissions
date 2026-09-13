class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>{});
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0], v = times[i][1], t = times[i][2];
            adj[u].push_back({v, t});
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();

            if (dist[node] < time) continue;

            for (auto& [nei, t] : adj[node]) {
                if (time + t < dist[nei]) {
                    dist[nei] = time + t;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
