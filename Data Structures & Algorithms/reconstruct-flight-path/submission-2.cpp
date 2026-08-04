class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;

        for(auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    void dfs(const string& node, unordered_map<string, multiset<string>>& adj, vector<string>& ans) {
        while(!adj[node].empty()) {
            string ele = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            dfs(ele, adj, ans);
        }

        ans.push_back(node);
    }
};
