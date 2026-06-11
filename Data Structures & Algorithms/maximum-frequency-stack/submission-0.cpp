class FreqStack {
private:
    stack<int> s;
    unordered_map<int, int> cnt;
public:
    FreqStack() {}
    
    void push(int val) {
        cnt[val]++;
        stack<int> temp;
        while(!s.empty() && cnt[val] < cnt[s.top()]) {
            temp.push(s.top());
            cnt[s.top()]--;
            s.pop();
        }
        s.push(val);
        while (!temp.empty()) {
            s.push(temp.top());
            cnt[temp.top()]++;
            temp.pop();
        }
    }

    int pop() {
        int ele = s.top();
        s.pop();
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