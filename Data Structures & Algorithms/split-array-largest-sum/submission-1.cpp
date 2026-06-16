class Solution {
private:
    int countSplit(vector<int>& v, long long m) {
        long long tmp = 0, cnt = 1;
        for(auto& x : v) {
            if (tmp + x > m) cnt++, tmp = x;
            else tmp += x;
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);

        long long l = *max_element(nums.begin(), nums.end()), r = sum, ans = sum;
        while (l < r) {
            long long m = l + (r - l) / 2;
            if (countSplit(nums, m) > k) l = m + 1;
            else ans = min(ans, m), r = m;
        }      

        return ans;
    }
};