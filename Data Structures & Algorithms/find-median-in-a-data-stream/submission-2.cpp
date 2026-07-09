class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num);

        if (!right.empty() and left.top() > right.top()) {
            right.push(left.top());
            left.pop();
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } 
        return left.top();
    }
};
