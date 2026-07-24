class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        
        if (visited.contains("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000");

        while(!q.empty()) {
            auto [str, turns] = q.front();
            q.pop();

            if (str == target) return turns;

            for (string s : combinations(str)) {
                if (!visited.contains(s)) {
                    visited.insert(s);
                    q.push({s, turns + 1});
                }
            }
        }

        return -1;
    }
private:
    vector<string> combinations(string& str) {
        vector<string> ans;
        for (int i = 0; i < 4; i++) {
            char ch = str[i];

            str[i] = (ch - '0' + 1) % 10 + '0';
            ans.push_back(str);
            str[i] = ch;

            str[i] = (ch - '0' - 1 + 10) % 10 + '0';
            ans.push_back(str);

            str[i] = ch;
        }
        return ans;
    }
};