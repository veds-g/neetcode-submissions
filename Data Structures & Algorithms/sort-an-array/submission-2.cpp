class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int mx = nums[r];

        int k = l;
        for (int i = l; i <= r - 1; i++) {
            if (nums[i] < mx) swap(nums[i], nums[k++]);
        }
        swap(nums[k], nums[r]);
        return k;
    }

    void quicksort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int p = partition(nums, l, r);

        quicksort(nums, l, p - 1);
        quicksort(nums, p + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quicksort(nums, 0, n - 1);
        return nums;
    }
};