class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;

        int prefix = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            ans += m[prefix - k];
            m[prefix]++;
        }
        return ans;
    }
};