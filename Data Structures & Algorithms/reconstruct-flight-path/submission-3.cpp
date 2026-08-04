class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;

        for(auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto& [src, dest] : adj) {
            sort(dest.rbegin(), dest.rend());
        }

        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    void dfs(const string& node, unordered_map<string, deque<string>>& adj, vector<string>& ans) {
        while(!adj[node].empty()) {
            string ele = adj[node].back();
            adj[node].pop_back();
            dfs(ele, adj, ans);
        }

        ans.push_back(node);
    }
};
