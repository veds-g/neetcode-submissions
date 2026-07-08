class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    
    // Sort by enqueue time, keeping original index
    vector<pair<int,int>> sorted_tasks(n);
    for (int i = 0; i < n; i++) sorted_tasks[i] = {tasks[i][0], i};
    sort(sorted_tasks.begin(), sorted_tasks.end());

    // Min-heap for available tasks: (processingTime, originalIndex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> available;

    vector<int> ans;
    long long time = 0;
    int i = 0;

    while (ans.size() < n) {
        // Enqueue all tasks available by current time
        while (i < n && tasks[sorted_tasks[i].second][0] <= time) {
            int idx = sorted_tasks[i].second;
            available.push({tasks[idx][1], idx});
            i++;
        }

        if (available.empty()) {
            // CPU idle: jump to next task's arrival
            time = tasks[sorted_tasks[i].second][0];
            continue;
        }

        auto [procTime, idx] = available.top(); available.pop();
        ans.push_back(idx);
        time += procTime;
    }

    return ans;
}
};