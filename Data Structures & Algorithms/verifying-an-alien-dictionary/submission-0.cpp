class Solution {
private:
    unordered_map<char, int> charIdx;

    bool isSorted(string& word1, string& word2) {
        int len1 = word1.size(), len2 = word2.size();
        int i1 = 0, i2 = 0;
        while(i1 < len1 and i2 < len2) {
            if (charIdx[word1[i1]] == charIdx[word2[i2]]) {
                i1++;
                i2++;
            } else if (charIdx[word1[i1]] < charIdx[word2[i2]]) {
                return true;
            } else {
                return false;
            }
        }
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); i++) {
            charIdx[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            if(!isSorted(word1, word2)) {
                return false;
            }
        }

        return true;
    }
};