class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 1;

        unordered_map<char, int> mp;
        for (auto& x : tasks) mp[x]++;

        priority_queue<pair<int, char>> pq;
        for (auto& x : mp) pq.push({x.second, x.first});

        unordered_map<char, int> temp;
        set<int> present;
        int idx = 1;
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();

            if (temp.contains(p.second)) {
                int charIdx = temp[p.second];
                int newIdx = charIdx + n + 1;
                while (present.contains(newIdx)) newIdx++;
                temp[p.second] = newIdx;
                present.insert(newIdx);
                ans = max(ans, newIdx);
            } else {
                while(present.contains(idx)) idx++;
                temp[p.second] = idx;
                present.insert(idx);
                ans = max(ans, idx);
            }

            if (p.first - 1 != 0) pq.push({p.first - 1, p.second});
        }

        return ans;
    }
};