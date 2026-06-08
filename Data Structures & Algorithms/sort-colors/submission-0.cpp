class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int idx = l, mx = nums[r];

        for (int i = l; i <= r - 1; i++)
            if (nums[i] < mx) swap(nums[i], nums[idx++]);

        swap(nums[idx], nums[r]);
        return idx; 
    }

    void quicksort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int p = partition(nums, l, r);
        quicksort(nums, l, p - 1);
        quicksort(nums, p + 1, r);
    }
    void sortColors(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
    }
};