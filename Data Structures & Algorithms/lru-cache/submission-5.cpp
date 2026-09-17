class LRUCache {
    list<int> cache;
    unordered_map<int, int> kv;
    unordered_map<int, list<int>::iterator> keyToList;
    int sz;
public:
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if (!kv.contains(key)) return -1;
        // move to end for existing searched key
        auto keyP = keyToList[key];
        cache.erase(keyP);
        cache.push_back(key);
        keyToList[key] = prev(cache.end());
        return kv[key];
    }
    
    void put(int key, int value) {
        if (kv.contains(key)) {
            // update existing: remove old position first
            cache.erase(keyToList[key]);
        } else if (cache.size() == sz) {
            // remove the top element
            int k = cache.front();
            cache.pop_front();
            kv.erase(k);
            keyToList.erase(k);
        }
        kv[key] = value;
        
        cache.push_back(key);
        keyToList[key] = prev(cache.end());
    }
};
