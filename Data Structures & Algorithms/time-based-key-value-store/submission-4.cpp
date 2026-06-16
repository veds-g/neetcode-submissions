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
        auto ub = upper_bound(temp.begin(), temp.end(), timestamp);
        if (ub == temp.begin()) return "";
        return val[*(prev(ub))];
    }
};
