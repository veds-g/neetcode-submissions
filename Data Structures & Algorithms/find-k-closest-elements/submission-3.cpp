class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), l = 0, r = n - 1;

        while (l <= r and r - l + 1 > k) {
            int diffl = abs(x - arr[l]), diffr = abs(x - arr[r]);
            if (diffl <=  diffr) {
                r--;
            } else {
                l++;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};