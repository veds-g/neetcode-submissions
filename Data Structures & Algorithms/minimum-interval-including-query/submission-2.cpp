class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> qs;
        for (int i = 0; i < queries.size(); i++) qs.push_back({queries[i], i});
        sort(qs.begin(), qs.end());

        vector<int> ans(queries.size());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int i = 0;

        for (auto [q, idx] : qs) {
            // add all intervals starting <= q
            while (i < intervals.size() && intervals[i][0] <= q)
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i++][1]});

            // remove intervals that ended before q
            while (!pq.empty() && pq.top().second < q) pq.pop();

            ans[idx] = pq.empty() ? -1 : pq.top().first;
        }

        return ans;
    }
};
