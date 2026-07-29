class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.contains(endWord)) return 0;
        if (beginWord == endWord) return 0;

        return bfs(beginWord, endWord, wordSet);
    }
private:
    int bfs(string& src, string& target, unordered_set<string>& wordSet) {
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

                for (int j = 0; j < src.size(); j++) {
                    char orig = curr[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        curr[j] = c;
                        if (wordSet.count(curr) && !vis.count(curr)) {
                            vis.insert(curr);
                            q.push(curr);
                        }
                        curr[j] = orig;
                    }
                }
            }
        }

        return 0;
    }
};
