class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool terminal = false;
    string word = "";
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
        curr -> word = s;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(auto& x : words) {
            trie.addWord(x);
        }

        int m = board.size(), n = board[0].size();

        set<string> res;
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, trie.root, res, -1);
            }
        }

        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, set<string>& res, int cameFrom) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '#') return;
        
        char temp = board[r][c];
        if (!node -> children.contains(temp)) return;

        TrieNode* next = node -> children[temp];
        if (next -> terminal) {
            res.insert(next -> word);
        }

        board[r][c] = '#';

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            if (i == cameFrom) continue;
            int opposite = (i + 2) % 4;
            dfs(board, r + dx[i], c + dy[i], next, res, opposite);
        }

        board[r][c] = temp;
        return;
    }
};
