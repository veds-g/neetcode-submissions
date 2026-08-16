class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ele = nums[0];
        for (auto& num : nums) {
            if (num == ele) cnt++;
            else cnt--;
            if (cnt == 0) ele = num, cnt++;
        }

        return ele;
    }
};