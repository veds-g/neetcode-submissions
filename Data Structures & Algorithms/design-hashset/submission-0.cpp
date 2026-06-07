class MyHashSet {
public:
    vector<int> v;

    MyHashSet() {  
    }
    
    void add(int key) {
        bool shouldAdd = true;
        for (int& x : v) if (x == key) shouldAdd = false;
        if (shouldAdd) v.push_back(key);
    }
    
    void remove(int key) {
        int shouldRemove = -1;
        for (int i = 0; i < v.size(); i++) if (v[i] == key) shouldRemove = i;
        if (shouldRemove != -1) v.erase(v.begin() + shouldRemove);
    }
    
    bool contains(int key) {
        for (int& x : v) if (x == key) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */