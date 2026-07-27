class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> idToNameMap;
        unordered_map<string, vector<string>> adj;

        for(auto& account : accounts) {
            for(int i = 1; i < account.size(); i++) {
                idToNameMap[account[i]] = account[0];
                if (i + 1 < account.size()) {
                    adj[account[i]].push_back(account[i + 1]);
                    adj[account[i + 1]].push_back(account[i]);
                }
            }
        }

        
        vector<vector<string>> ans;
        unordered_set<string> vis;
        for(auto& [k, _] : idToNameMap) {
            if (!vis.contains(k)) {
                set<string> sortedAccounts;
                dfs(adj, k, vis, sortedAccounts);
                vector<string> temp = {idToNameMap[k]};
                vector<string> accn(sortedAccounts.begin(), sortedAccounts.end());
                temp.insert(temp.end(), accn.begin(), accn.end());
                ans.push_back(temp);
            }
        }

        return ans;
    }
private:
    void dfs(
        unordered_map<string, vector<string>>& adj, 
        string node, 
        unordered_set<string>& vis, 
        set<string>& sortedAccounts
    ) {
        vis.insert(node);
        sortedAccounts.insert(node);

        for(auto& s : adj[node]) {
            if(!vis.contains(s)) {
                dfs(adj, s, vis, sortedAccounts);
            }
        }
    }
};