class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int sum = v[l] + v[r];
            if (sum == t) return {l + 1, r + 1};
            else if (sum > t) r--;
            else l++;
        }

        return {};
    }
};
