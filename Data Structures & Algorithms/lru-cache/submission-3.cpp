class LRUCache {
private:
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> kv;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (kv.contains(key)) {
            list<int>::iterator l = kv[key].second;
            int val = kv[key].first;
            keys.erase(l);
            keys.push_back(key);
            kv[key].second = prev(keys.end());
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (kv.contains(key)) {
            keys.erase(kv[key].second);
        } else if (keys.size() == cap) {
            int k = keys.front();
            keys.pop_front();
            kv.erase(k);
        }
        keys.push_back(key);
        kv[key] = {value, prev(keys.end())};
    }
};
