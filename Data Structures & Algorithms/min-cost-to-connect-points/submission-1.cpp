class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> adj;

        int n = points.size();
        for(int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        unordered_set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});

        int ans = 0;
        while(!pq.empty()) {
            auto [wt, node] = pq.top(); pq.pop();
            
            if (vis.contains(node)) continue;
            ans += wt;
            vis.insert(node);

            for (auto& nei : adj[node]) {
                if (!vis.contains(nei.first)) pq.push({nei.second, nei.first});
            }
        }

        return ans;
    }
};
