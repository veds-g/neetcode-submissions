class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> m;
        for (auto& meeting : meetings) m.push(meeting);

        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<>> rooms;
        for (int i = 0; i < n; i++) rooms.push(i);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;

        int time = 0;
        while (!m.empty()) {
            auto meet = m.top(); m.pop();
            time = max(time, meet[0]);

            while (!busy.empty() and busy.top().first <= time) {
                auto ele = busy.top(); busy.pop();
                rooms.push(ele.second);
            }

            if (!rooms.empty()) {
                int room = rooms.top(); rooms.pop();
                count[room]++;
                busy.push({meet[1], room});
            } else {
                auto [end, r] = busy.top(); busy.pop();
                count[r]++;
                busy.push({end + meet[1] - meet[0], r});
            }
        }

        int mx = INT_MIN, ans = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > mx) {
                mx = count[i];
                ans = i;
            }
        }

        return ans;
    }
};