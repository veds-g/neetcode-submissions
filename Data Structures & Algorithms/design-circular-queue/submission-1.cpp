class MyCircularQueue {
private:
    vector<int> v;
    int l = 0, r = -1, n = 0, s = 0;
public:
    MyCircularQueue(int k) {
        v.resize(k, -1);
        n = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        r = (r + 1) % n;
        v[r] = value;
        s++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        l = (l + 1) % n;
        s--;
        return true;
    }
    
    int Front() {
        if (s == 0) return -1;
        return v[l];
    }
    
    int Rear() {
        if (s == 0) return -1;
        return v[r];
    }
    
    bool isEmpty() {
        return s == 0;
    }
    
    bool isFull() {
        if(s == n) return true;
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