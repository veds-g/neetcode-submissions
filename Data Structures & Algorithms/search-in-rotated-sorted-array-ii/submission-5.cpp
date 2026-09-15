class Solution {
public:
    bool search(vector<int>& n, int t) {
        int l = 0, r = n.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (n[mid] == t) return true;
            
            if (n[mid] < n[l]) {
                if (n[mid] < t && t <= n[r]) l = mid + 1;
                else r = mid - 1;
            } else if (n[l] < n[mid]) {
                if (n[l] <= t && t < n[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                l++;
            }
        }

        return false;
    }
};