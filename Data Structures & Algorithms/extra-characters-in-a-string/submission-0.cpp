class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool terminal;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void addWord(string s) {
        TrieNode* curr = root;
        for(auto& x : s) {
            if (!curr -> children.contains(x)) {
                curr -> children[x] = new TrieNode();
            }
            curr = curr -> children[x];
        }
        curr -> terminal = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for(auto&x : dictionary) {
            trie.addWord(x);
        }

        int n = s.size();
        vector<int> dp(n + 1, -1);
        dp[n] = 0;

        return dfs(0, s, dp, trie.root);
    }
private:
    int dfs(int i, string& s, vector<int>& dp, TrieNode* root) {
        if (dp[i] != -1) return dp[i];

        TrieNode* curr = root;
        int res = 1 + dfs(i + 1, s, dp, root);
        for(int j = i; j < s.size(); j++) {
            if (!curr -> children.contains(s[j])) break;
            curr = curr -> children[s[j]];

            if (curr -> terminal) res = min(res, dfs(j + 1, s, dp, root));
        }

        dp[i] = res;
        return res;
    }
};