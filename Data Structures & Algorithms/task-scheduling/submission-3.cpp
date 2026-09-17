class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mp;

        for (auto& t : tasks) {
            mp[t - 'A']++;
        }

        priority_queue<pair<int, int>> pq;
        queue<tuple<int, int, int>> q;

        for (auto& x : mp) {
            pq.push({x.second, x.first});
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            if (pq.empty()) {
                time = get<0>(q.front());
            } else {
                time++;
            }

            while(!q.empty() and get<0>(q.front()) == time) {
                auto [ts, freq, cnt] = q.front();
                q.pop();
                pq.push({freq, cnt});
            }

            if (!pq.empty()) {
                auto ele = pq.top(); pq.pop();
                if (ele.first > 1) q.push({time + n + 1, ele.first - 1, ele.second});
            }
        }

        return time;
    }
};
