class Solution {
private:
    bool dfs(int node, int par, unordered_map<int, vector<int>>& adj, vector<bool>& vis) {
        if (vis[node]) return false;
        vis[node] = true;

        for(int& nei : adj[node]) {
            if (nei == par) continue;
            if (!dfs(nei, node, adj, vis)) {
                return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        if (!dfs(0, -1, adj, vis)) {
            return false;
        }

        for (int i = 0; i < n; i++) if (!vis[i]) return false;

        return true;
    }
};
