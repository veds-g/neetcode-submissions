class FreqStack {
private:
    unordered_map<int, int> cnt;           // val → frequency
    unordered_map<int, stack<int>> group;  // freq → stack of vals
    int maxFreq = 0;
public:
    FreqStack() {}
    
    void push(int val) {
        cnt[val]++;
        maxFreq = max(maxFreq, cnt[val]);
        group[cnt[val]].push(val);         // O(1)
    }

    int pop() {
        int val = group[maxFreq].top();    // O(1)
        group[maxFreq].pop();
        cnt[val]--;
        if (group[maxFreq].empty()) maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */