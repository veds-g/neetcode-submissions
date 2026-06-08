class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto&x : nums) mp[x]++;

        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b) {return a.second > b.second;});

        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = v[i].first;
        return res;
    }
};
