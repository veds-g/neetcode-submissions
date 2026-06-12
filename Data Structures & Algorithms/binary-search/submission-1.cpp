class Solution {
public:
    int search(vector<int>& v, int t) {
        int l = 0, r = v.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid] == t) return mid;
            else if (v[mid] < t) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};
