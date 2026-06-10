class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1 = 0, l2 = 0;
        while (l1 < m + l2 && l2 < n) {
            if (nums1[l1] <= nums2[l2]) {
                l1++;
            } else {
                for (int i = m + n - 2; i >= l1; i--) 
                    nums1[i + 1] = nums1[i];
                nums1[l1] = nums2[l2];
                l1++;
                l2++;

            }
        }

        while (l2 < n) {
            nums1[l1++] = nums2[l2++];
        }
    }
};