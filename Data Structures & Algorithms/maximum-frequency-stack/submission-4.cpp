class FreqStack {
    vector<stack<int>> v;
    unordered_map<int, int> cnt;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        cnt[val]++;

        while(v.size() < cnt[val]) v.push_back(stack<int>{});
        v[cnt[val] - 1].push(val);
    }
    
    int pop() {
        int ele = v.back().top();
        v.back().pop();
        if (v.back().empty()) v.pop_back();
        cnt[ele]--;
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */