class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        unordered_map<int, unordered_set<int>> freqToElements;

        int mx = INT_MIN;

        for (auto& num : nums) {
            if (freq.contains(num)) {
                freqToElements[freq[num]].erase(num);
            }

            freq[num]++;
            mx = max(mx, freq[num]);
            freqToElements[freq[num]].insert(num);
        }

        vector<int> ans;
        for (int i = mx; i > 0; i--) {
            if (!freqToElements.contains(i)) continue;

            for(auto& x : freqToElements[i]) {
                ans.push_back(x);
                if (ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
