class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mn = 1;
        unordered_set<int> s;
        for (int& x : nums) {
            if (x <= 0) continue;
            s.insert(x);
        }
        while (true) {
            if (s.contains(mn)) mn++;
            else break;
        }
        return mn;
    }
};