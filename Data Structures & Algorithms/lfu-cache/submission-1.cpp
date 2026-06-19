class LFUCache {
private:
    struct Node {
        int value, freq;
    };
    unordered_map<int, Node> cache;                    // key -> {value, freq}
    unordered_map<int, list<int>> freqList;             // freq -> keys (LRU order within freq)
    unordered_map<int, list<int>::iterator> pointer;    // key -> iterator in freqList[freq]
    int minFreq = 0, cap;

    void touch(int key) {
        int freq = cache[key].freq++;
        freqList[freq].erase(pointer[key]);
        if (freqList[freq].empty() && minFreq == freq) minFreq++;

        freqList[freq + 1].push_back(key);
        pointer[key] = prev(freqList[freq + 1].end());
    }

public:
    LFUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (!cache.contains(key)) return -1;
        touch(key);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (cache.contains(key)) {
            cache[key].value = value;
            touch(key);
            return;
        }

        if ((int)cache.size() == cap) {
            int evict = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            pointer.erase(evict);
            cache.erase(evict);
        }

        cache[key] = {value, 1};
        freqList[1].push_back(key);
        pointer[key] = prev(freqList[1].end());
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */