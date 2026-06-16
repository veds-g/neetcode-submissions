class TimeMap {
private:
    unordered_map<string, vector<int>> mp;
    unordered_map<int, string> val;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        val[timestamp] = value;

        if (mp.contains(key)) mp[key].push_back(timestamp);
        else mp[key] = {timestamp};
    }
    
    string get(string key, int timestamp) {
        if (!mp.contains(key)) return "";
        vector<int> temp = mp[key];
        auto lb = lower_bound(temp.begin(), temp.end(), timestamp);
        if (lb == temp.end()) return val[temp.back()];
        if (*lb == timestamp) return val[*lb];
        if (lb == temp.begin() and *lb > timestamp) return "";
        return val[*(--lb)];
    }
};
