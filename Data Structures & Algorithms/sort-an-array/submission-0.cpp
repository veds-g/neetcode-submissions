class Solution {
public:

    void merge(vector<int>& nums, int left, int mid, int right) {
        int l1 = mid - left + 1;
        int l2 = right - mid;

        vector<int> v(right - left + 1);
        int i = 0, j = 0, k = 0;
        while (i < l1 && j < l2) {
            if (nums[i + left] <= nums[j + mid + 1]) {
                v[k++] = nums[i + left];
                i++;
            } else {
                v[k++] = nums[j + mid + 1];
                j++;
            }
        }
        while (i < l1) v[k++] = nums[i++ + left];
        while (j < l2) v[k++] = nums[j++ + mid + 1];

        for (int i = 0; i < v.size(); i++) nums[i + left] = v[i];
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};