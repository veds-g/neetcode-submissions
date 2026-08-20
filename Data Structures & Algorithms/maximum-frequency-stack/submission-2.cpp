class FreqStack {
    unordered_map<int, int> freq;
    vector<stack<int>> fstk;
public:
    FreqStack() {}
    
    void push(int val) {
        freq[val]++;

        int newFreq = freq[val];
        if (newFreq > fstk.size()) {
            stack<int> newMax;
            newMax.push(val);
            fstk.push_back(newMax);
        } else {
            fstk[newFreq - 1].push(val);
        }
    }
    
    int pop() {
        int ele = fstk.back().top();
        fstk.back().pop();
        if (fstk.back().size() == 0) fstk.pop_back();
        freq[ele]--;
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */