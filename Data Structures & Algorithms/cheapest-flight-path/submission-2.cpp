class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({0, src});

        k += 1;

        while(k-- and !q.empty()) {
            int sz = q.size();
            vector<int> temp = dist;
            for(int l = 0; l < sz; l++) {
                auto [pathSum, node] = q.front(); q.pop();
                if (pathSum > dist[node]) continue;

                for(auto& [nei, cost] : adj[node]) {
                    int currPathSum = pathSum + cost;
                    if (currPathSum < temp[nei]) {
                        temp[nei] = currPathSum;
                        q.push({currPathSum, nei});
                    }
                }
            }
            dist = temp;
        } 

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
