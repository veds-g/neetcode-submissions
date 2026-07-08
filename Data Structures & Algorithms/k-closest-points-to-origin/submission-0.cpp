class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        auto cmp = [](vector<int> a, vector<int> b) {
            return sqrt(pow(a[0], 2) + pow(a[1], 2)) < sqrt(pow(b[0], 2) + pow(b[1], 2));
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (auto& x : points) {
            pq.push(x);
            if (pq.size() > k) pq.pop();
        }

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
