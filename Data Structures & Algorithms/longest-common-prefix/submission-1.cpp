class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* curr = root;

        for (char c : word) {
            if (!curr -> children.contains(c))
                curr -> children[c] = new TrieNode();
            curr = curr -> children[c];
        }
    }

    int lcp(string& word, int prefix) {
        TrieNode* curr = root;

        int maxRep = min((int)word.size(), prefix);
        for(int i = 0; i < maxRep; i++) {
            if (!curr -> children.contains(word[i]))
                return i;
            curr = curr -> children[word[i]];
        }

        return maxRep;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        int minIdx = 0;
        for (int i = 1; i < strs.size(); i++)
            if (strs[i].size() > strs[minIdx].size())
                minIdx = i;

        Trie trie;
        trie.insert(strs[minIdx]);
        int prefixLen = strs[minIdx].size();

        for (int i = 0; i < strs.size(); i++)
            prefixLen = trie.lcp(strs[i], prefixLen);

        return strs[0].substr(0, prefixLen);
    }
};