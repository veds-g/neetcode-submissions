class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        if (beginWord == endWord) return 0;
        
        unordered_map<string, unordered_set<string>> adj;

        wordList.push_back(beginWord);
        int sz = wordList.size(), n = beginWord.size();
        
        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                int cnt = 0;
                for(int k = 0; k < n; k++) {
                    if(wordList[i][k] != wordList[j][k]) cnt++;
                }
                if (cnt == 1) {
                    adj[wordList[i]].insert(wordList[j]);
                    adj[wordList[j]].insert(wordList[i]);
                }
            }
        }

        return bfs(beginWord, endWord, adj);
    }
private:
    int bfs(string& src, string& target, unordered_map<string, unordered_set<string>>& adj) {
        int ans = 0;

        queue<string> q;
        unordered_set<string> vis;
        q.push(src);
        vis.insert(src);

        while(!q.empty()) {
            ans++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string curr = q.front(); q.pop();
                if (curr == target) return ans;

                for (auto& nei : adj[curr]) {
                    if (!vis.contains(nei)) {
                        vis.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }

        return 0;
    }
};
