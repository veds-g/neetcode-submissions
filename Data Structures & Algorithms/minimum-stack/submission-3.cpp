class MinStack {
    stack<pair<int, int>> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push({val, val});
        } else {
            pair<int, int> p = stk.top();
            stk.push({val, min(val, p.second)});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
