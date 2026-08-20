class MinStack {
    stack<int> s1, s2;
public:
    MinStack() {}
    
    void push(int val) {
        s1.push(val);

        int top = s2.empty() ? INT_MAX : s2.top();
        top = min(top, val);
        s2.push(top);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
