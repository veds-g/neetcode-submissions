class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        unordered_set<char> vis;
        
        for (string w : words) {
            for (char c : w) {
                vis.insert(c);
                indegree[c] = 0;
            }
        }

        int n = words.size();

        for (int i = 0; i < n - 1; i++) {
            string& w1 = words[i], w2 = words[i + 1];

            if (w1.size() > w2.size() and w1.starts_with(w2)) return "";

            int len = min(w1.size(), w2.size());
            for (int x = 0; x < len; x++) {
                if (w1[x] != w2[x]) {
                    if (!adj[w1[x]].contains(w2[x])) {
                        adj[w1[x]].insert(w2[x]);
                        indegree[w2[x]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto& ch : vis) {
            if (indegree[ch] == 0) {
                q.push(ch);
            }
        }

        string ans = "";

        while(!q.empty()) {
            char ch = q.front();
            q.pop();

            ans += ch;
        
            for(auto& nei : adj[ch]) {
                indegree[nei]--;
                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return ans.size() == vis.size() ? ans : "";
    }
};
