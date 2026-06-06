class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        for (int i = 0; i < strs[0].size(); i++) {
            int isMatching = true;
            char curr = strs[0][i];
            for (auto &x : strs) {
                if (x[i] != curr)
                    isMatching = false;
            }
            if (isMatching) ans += curr;
            else break;
        }

        return ans;
    }
};