class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool terminal;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (auto& x : word) {
            if (!curr -> children.contains(x)) 
                curr -> children[x] = new TrieNode();    
            curr = curr -> children[x];
        }
        curr -> terminal = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (auto& x : word) {
            if (curr -> children.contains(x)) {
                curr = curr -> children[x];
            } else {
                return false;
            }
        }
        return curr -> terminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto& x : prefix) {
            if (curr -> children.contains(x)) {
                curr = curr -> children[x];
            } else {
                return false;
            }
        }
        return true;
    }
};
