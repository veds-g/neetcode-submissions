/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &a) {
        int l = 1, r = a.length() - 2, midx = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (a.get(m) > a.get(m - 1) and a.get(m) > a.get(m + 1)) {
                midx = m;
                break;
            } else if (a.get(m - 1) < a.get(m) and a.get(m) < a.get(m + 1)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        l = 0, r = midx;
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (a.get(m) == t) return m;
            else if (a.get(m) < t) l = m + 1;
            else r = m - 1;
        }

        l = midx + 1, r = a.length() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (a.get(m) == t) return m;
            else if (a.get(m) < t) r = m - 1;
            else l = m + 1;
        }

        return -1;
    }
};