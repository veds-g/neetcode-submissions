class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& x : nums) m[x]++;

        vector<int> res;
        for (pair<const int ,int>& x : m) {
            if (x.second > nums.size() / 3) res.push_back(x.first);
        } 

        return res;
    }
};