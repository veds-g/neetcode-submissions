class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, k = 0;
        while (idx < nums.size()) {
            if (nums[idx] == nums[k]) idx++;
            else nums[++k] = nums[idx++];
        } 
        return k + 1;
    }
};