class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for (const int& x : nums) mp[x]++;

        int idx = 0;
        for (int i = mn; i <= mx; i++) {
            while(mp[i] > 0) {
                nums[idx++] = i;
                mp[i]--;
            }
        }
    }
};