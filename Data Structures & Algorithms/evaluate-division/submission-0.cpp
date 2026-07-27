class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> adj;
    double dfs(
        unordered_set<string>& vis, 
        string& src, 
        string& dest
    ) {
        if(src == dest) {
            return 1.0;
        }

        vis.insert(src);

        for(auto& [nei, w] : adj[src]) {
            if(vis.contains(nei)) continue;

            double res = dfs(vis, nei, dest);
            if (res != -1.0) return w * res;
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> ans;
        for(int i = 0; i < queries.size(); i++) {
            string src = queries[i][0], dest = queries[i][1];

            if (!adj.count(src) || !adj.count(dest)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;
            ans.push_back(dfs(vis, src, dest));
        }

        return ans;
    }
};