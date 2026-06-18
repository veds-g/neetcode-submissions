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
        if (isFull()) return false;
        v[r] = value;
        r = (r + 1) % n;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        l = (l + 1) % n;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return v[l];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return v[(r - 1 + n) % n];
    }
    
    bool isEmpty() {
        return l == r;
    }
    
    bool isFull() {
        return (r + 1) % n == l;
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