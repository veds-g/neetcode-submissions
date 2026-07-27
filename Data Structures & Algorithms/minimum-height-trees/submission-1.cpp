class Solution {
private:
    unordered_map<int, vector<int>> adj;

    int dfs(int node, vector<int>& vis) {
        vis[node] = 1;

        int h = INT_MIN;
        for(auto x : adj[node]) {
            if(vis[x] == 1) continue;
            int currH = dfs(x, vis);
            if(currH > h) {
                h = currH;
            }
        }

        return h == INT_MIN ? 0 : h + 1;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int h = INT_MAX;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            int height = dfs(i, vis);

            if(height < h) {
                h = height;
                ans.clear();
                ans.push_back(i);
            } else if (height == h) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};