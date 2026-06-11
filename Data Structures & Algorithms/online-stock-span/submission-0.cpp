class StockSpanner {
private:
    stack<int> stk;
public:
    StockSpanner() {}
    
    int next(int price) {
        stk.push(price);

        int cnt = 0;
        stack<int> tmp;
        while(!stk.empty() and stk.top() <= price) {
            cnt++;
            tmp.push(stk.top());
            stk.pop();
        }
        while(!tmp.empty()) stk.push(tmp.top()), tmp.pop();

        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */