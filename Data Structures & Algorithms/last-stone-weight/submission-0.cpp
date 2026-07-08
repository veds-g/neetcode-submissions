class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto& x : stones) pq.push(x);

        while(true) {
            if (pq.size() == 0 || pq.size() == 1) break;
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            int diff = first - second;
            if (diff) pq.push(diff);
        }

        pq.push(0);
        return pq.top();
    }
};
