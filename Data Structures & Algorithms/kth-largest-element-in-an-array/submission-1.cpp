class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    int quickselect(vector<int>& nums, int l, int r, int k) {
        
        if (l == r) return nums[l];
        
        int pivot = partition(nums, l, r);

        if (pivot == k) {
            return nums[k];
        } if (pivot < k) {
            return quickselect(nums, pivot + 1, r, k);
        } else {
            return quickselect(nums, l, pivot - 1, k);
        }
    }

    int partition(vector<int>& nums, int l, int r) {
        int randIdx = l + rand() % (r - l + 1);
        swap(nums[randIdx], nums[r]);
        
        int i = l;
        int pivot = nums[r];

        for (int j = l; j < r; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[r]);
        return i;
    }
};
