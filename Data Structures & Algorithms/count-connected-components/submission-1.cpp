class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> vis;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(vis.contains(i)) continue;
            dfs(i, -1, vis, adj);
            cnt++;
        }

        return cnt;
    }

    void dfs(int node, int par, unordered_set<int>& vis, unordered_map<int, vector<int>>& adj) {
        vis.insert(node);

        for(int& nei : adj[node]) {
            if(nei == par || vis.contains(nei)) continue;
            dfs(nei, node, vis, adj);
        }
    }
};
