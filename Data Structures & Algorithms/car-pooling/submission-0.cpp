class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            pq.push(trips[i]);
        }

        auto cmp1 = [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp1)> pq1(cmp1);

        int currCap = 0;
        while (!pq.empty()) {
            int time = pq.top()[1];

            while (!pq1.empty() and pq1.top()[2] <= time) {
                vector<int> temp = pq1.top(); pq1.pop();
                currCap -= temp[0];
            }

            while (!pq.empty() and pq.top()[1] <= time) {
                vector<int> temp = pq.top(); pq.pop();
                currCap += temp[0];
                if (currCap > capacity) return false;
                pq1.push(temp);
            }
        }

        return true;
    }
};