class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < v.size(); i++) {
            int ele = v[i];
            int diff = target - ele;
            
            if (m.contains(diff)) return {m[diff], i};
            m[ele] = i;
        }
        return {0, 0};
    }
};
