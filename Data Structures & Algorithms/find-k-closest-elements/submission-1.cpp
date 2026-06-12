class Solution {
private:
    int getDiff(int x, int k) {
        return abs(x - k);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = -1, diff = INT_MAX, n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            int val = getDiff(x, arr[i]);
            if (val < diff) diff = val, idx = i;
        }

        int l = idx - 1, r = idx;
        while (r - l - 1 < k) {
            if (l < 0) {
                r++;
            } else if (r >= arr.size()) {
                l--;
            } else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                l--;
            } else {
                r++;
            }
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};