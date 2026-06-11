class MinStack {
private:
    multiset<int> s;
    stack<int> stk;
public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        s.insert(val);
    }
    
    void pop() {
        int ele = stk.top();
        stk.pop();
        auto it = s.find(ele);
        s.erase(it);
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return *s.begin();
    }
};
