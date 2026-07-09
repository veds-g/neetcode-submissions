class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (left.empty() or right.empty()) {
            right.push(num);
            int diff = abs((int)left.size() - (int)right.size());
            if (diff > 1) {
                left.push(right.top());
                right.pop();
            }
        }
        else {
            if (num <= left.top()) {
                left.push(num);
                if (left.size() - right.size() > 1) {
                    right.push(left.top());
                    left.pop();
                }
            } else {
                right.push(num);
                if (right.size() - left.size() > 1) {
                    left.push(right.top());
                    right.pop();
                }
            }
        }
    }
    
    double findMedian() {
        int l = left.empty() ? INT_MIN : left.top();
        int r = right.empty() ? INT_MAX : right.top();
        cout << l << " " << r << endl;

        if (left.size() == right.size()) {
            if (l == INT_MIN || r == INT_MAX) return 0.0;
            else return (l + r) / 2.0;
        } else if (left.size() > right.size()) {
            return (double)l;
        } else {
            return (double)r;
        }
    }
};
