class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        vector<vector<int>> sortedCap(n);

        for(int i = 0; i < n; i++) {
            sortedCap[i] = {capital[i], i};
        }

        sort(sortedCap.begin(), sortedCap.end());

        priority_queue<int> pq;
        int i = 0;
        while(k--) {
            while(i < n and sortedCap[i][0] <= w) {
                pq.push(profits[sortedCap[i][1]]);
                i++;
            }

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};