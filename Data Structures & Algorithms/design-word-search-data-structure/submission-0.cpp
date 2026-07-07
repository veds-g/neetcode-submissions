class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool terminal;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto& x : word) {
            if (!curr -> children.contains(x)) {
                curr -> children[x] = new TrieNode();
            }
            curr = curr -> children[x];
        }
        curr -> terminal = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private: 
    bool dfs(string& word, int j, TrieNode* root) {
        TrieNode* curr = root;

        for(int i = j; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for(auto x : curr -> children) {
                    if (x.second != NULL and dfs(word, i + 1, x.second)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!curr -> children.contains(c)) {
                    return false;
                }
                curr = curr -> children[c];
            }
        }
        return curr -> terminal;
    }
};
