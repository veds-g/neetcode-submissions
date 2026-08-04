class Solution {
private: 
    int hash(int i, int j) {
        return i * 2000 + j;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> adj;

        int n = points.size();
        for(int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int h1 = hash(points[i][0], points[i][1]);
                int h2 = hash(points[j][0], points[j][1]);

                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[h1].push_back({h2, dist});
                adj[h2].push_back({h1, dist});
            }
        }

        unordered_set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, hash(points[0][0], points[0][1])});

        int ans = 0;
        while(!pq.empty()) {
            auto [wt, node] = pq.top(); pq.pop();
            
            if (vis.contains(node)) continue;
            ans += wt;
            vis.insert(node);

            for (auto& nei : adj[node]) {
                pq.push({nei.second, nei.first});
            }
        }

        return ans;
    }
};
