class MyCircularQueue {
private:
    vector<int> v;
    int l = 0, r = 0, n = 0;
public:
    MyCircularQueue(int k) {
        v.resize(k + 1);
        n = k + 1;
    }
    
    bool enQueue(int value) {
        int idx = (r + 1) % n;
        if (idx == l) return false;
        v[r] = value;
        r = idx;
        return true;
    }
    
    bool deQueue() {
        if (l == r) return false;
        l = (l + 1) % n;
        return true;
    }
    
    int Front() {
        if (l == r) return -1;
        return v[l];
    }
    
    int Rear() {
        if (l == r) return -1;
        return v[(r - 1 + n) % n];
    }
    
    bool isEmpty() {
        if (l == r) return true;
        return false;
    }
    
    bool isFull() {
        int idx = (r + 1) % n;
        if (idx == l) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */