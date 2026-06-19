class LFUCache {
private:
    unordered_map<int, list<int>> freqList;    
    unordered_map<int, int> keyFreq;
    unordered_map<int, int> kv;
    unordered_map<int, list<int>::iterator> pointer;
    int minFreq;
    int cap;
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyFreq.contains(key)) {
            int ans = kv[key];

            int curr = keyFreq[key]++;
            freqList[curr].erase(pointer[key]);
            if (minFreq == curr and freqList[curr].size() == 0) 
                minFreq = curr + 1;
            freqList[curr + 1].push_back(key);
            pointer[key] = prev(freqList[curr + 1].end());
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keyFreq.contains(key)) {
            int curr = keyFreq[key]++;
            freqList[curr].erase(pointer[key]);
            if (minFreq == curr and freqList[curr].size() == 0) 
                minFreq = curr + 1;
            freqList[curr + 1].push_back(key);
            pointer[key] = prev(freqList[curr + 1].end());
            kv[key] = value;
            return;
        } 
        
        if (keyFreq.size() == cap) {
            int ele = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyFreq.erase(ele);
            kv.erase(ele);
            pointer.erase(ele);
        }
        kv[key] = value;
        keyFreq[key] = minFreq = 1;
        freqList[1].push_back(key);
        pointer[key] = prev(freqList[1].end());
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */