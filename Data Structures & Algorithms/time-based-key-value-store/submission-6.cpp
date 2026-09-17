class TimeMap {
private:
    unordered_map<string, map<int, string>> ts;
    unordered_map<string, string> mp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        ts[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!ts.contains(key)) return "";
        auto ub = ts[key].upper_bound(timestamp);
        if (ub == ts[key].begin()) return "";
        return prev(ub)->second;
    }
};
