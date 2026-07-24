class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> vis;
        if(!dfs(0, -1, vis, adj)) {
            return false;
        }

        return vis.size() == n;
    }
private:
    bool dfs(int node, int par, unordered_set<int>& vis, unordered_map<int, vector<int>>& adj) {
        if(vis.contains(node)) return false;

        vis.insert(node);
        for(int nextNode: adj[node]) {
            if(nextNode == par) {
                continue;
            }
            if(!dfs(nextNode, node, vis, adj)) {
                return false;
            }
        }

        return true;
    }
};
