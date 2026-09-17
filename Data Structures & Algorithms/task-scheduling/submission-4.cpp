class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mp;

        for (auto& t : tasks) {
            mp[t - 'A']++;
        }

        priority_queue<pair<int, int>> pq;
        queue<vector<int>> q;

        for (auto& x : mp) {
            pq.push({x.second, x.first});
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            if (pq.empty()) {
                time = q.front()[0];
            } else {
                time++;
            }

            while(!q.empty() and q.front()[0] == time) {
                pq.push({q.front()[1], q.front()[2]});
                q.pop();
            }

            if (!pq.empty()) {
                auto ele = pq.top(); pq.pop();
                if (ele.first > 1) q.push({time + n + 1, ele.first - 1, ele.second});
            }
        }

        return time;
    }
};
