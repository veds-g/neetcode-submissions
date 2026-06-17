class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) a.swap(b);

        int m = a.size(), n = b.size();
        int mid = (m + n + 1) / 2;

        int l = 0, r = m;
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = mid - i;

            int Aleft = i > 0 ? a[i - 1] : INT_MIN;
            int Aright = i < a.size() ? a[i] : INT_MAX;
            int Bleft = j > 0 ? b[j - 1] : INT_MIN;
            int Bright = j < b.size() ? b[j] : INT_MAX;

            if (Aleft <= Bright and Bleft <= Aright) {
                if ((m + n) % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }    

        return -1;
    }
};