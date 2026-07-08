class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (auto& x : s) mp[x]++;

        priority_queue<pair<int, char>> pq;
        for (auto& x : mp) pq.push({x.second, x.first});

        string ans = "";
        pair<int, char> prev = {0, ' '};
        while (!pq.empty() || prev.first > 0) {
            if (prev.first > 0 and pq.empty()) {
                return "";
            }

            auto [count, ch] = pq.top();
            pq.pop();
            ans += ch;
            count--;

            if (prev.first > 0) {
                pq.push(prev);
            }

            prev = {count, ch};
        }
        
        return ans;
    }
};