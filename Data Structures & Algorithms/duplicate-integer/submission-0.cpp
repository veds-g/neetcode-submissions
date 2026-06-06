class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto &x : nums) {
            if (s.contains(x)) return true;
            s.insert(x);
        }
        return false;
    }
};