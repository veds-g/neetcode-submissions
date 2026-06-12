class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // store indices, compare by value
        auto cmp = [&](int a, int b){ return nums[a] < nums[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        vector<int> res;
        for (int i = 0; i < k; i++) pq.push(i);
        res.push_back(nums[pq.top()]);

        for (int i = k; i < nums.size(); i++) {
            pq.push(i);
            while (!pq.empty() && pq.top() <= i - k) pq.pop();
            res.push_back(nums[pq.top()]);
        }

        return res;
    }
};