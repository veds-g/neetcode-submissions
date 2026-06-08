class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (auto& s : strs) {
            int n = s.size();
            ans += to_string(n) + '#' + s; 
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size(); i++) {
            string size = "";
            while(s[i] != '#') {
                size += s[i];
                i++;
            }
            int val = stoi(size);
            string tmp = "";
            while (val--) {
                tmp += s[++i];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
