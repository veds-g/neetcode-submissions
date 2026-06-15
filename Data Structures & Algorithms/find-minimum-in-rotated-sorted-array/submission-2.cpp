class Solution {
public:
    int findMin(vector<int> &a) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] < a[r]) r = mid;
            else l = mid + 1;
        }
        return a[l];
    }
};
