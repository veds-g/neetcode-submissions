class MinStack {
private:
    stack<int> s1, s2;
public:
    MinStack() {}
    
    void push(int val) {
        s1.push(val);
        if (s2.empty()) {
            s2.push(val);
        } else if (val <= s2.top()) {
            s2.push(val);
        }
    }
    
    void pop() {
        int ele = s1.top();
        s1.pop();
        if (ele == s2.top()) {
            s2.pop();
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
