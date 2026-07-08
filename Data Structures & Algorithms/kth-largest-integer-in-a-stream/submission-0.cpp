class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int len;
public:
    KthLargest(int k, vector<int>& nums) {
        len = k;
        for (auto& x : nums) {
            pq.push(x);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > len) pq.pop();
        return pq.top();
    }
};
