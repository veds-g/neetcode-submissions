class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<pair<int, int>> sortedEQ(n);
        for(int i = 0; i < n; i++) sortedEQ[i] = {tasks[i][0], i};
        sort(sortedEQ.begin(), sortedEQ.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> ans;
        long long time = 0;
        int i = 0;

        while (ans.size() < n) {
            while (i < n and tasks[sortedEQ[i].second][0] <= time) {
                int idx = sortedEQ[i].second;
                pq.push({tasks[idx][1], idx});
                i++;
            }

            if (pq.empty()) {
                time = tasks[sortedEQ[i].second][0];
                continue;
            }

            ans.push_back(pq.top().second);
            time += pq.top().first;
            pq.pop();
        }
        return ans;
    }
};