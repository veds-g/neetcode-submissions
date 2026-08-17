class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1, cnt1 = 0, ele2 = -1, cnt2 = 0, n = nums.size();

        for (auto& x : nums) {
            if (x == ele1) {
                cnt1++;
            } else if (x == ele2) {
                cnt2++;
            } else if (cnt1 == 0) {
                ele1 = x;
                cnt1++;
            } else if (cnt2 == 0) {
                ele2 = x;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == ele1) cnt1++;
            else if (num == ele2) cnt2++;
        }

        vector<int> ans;
        if (cnt1 > n / 3) ans.push_back(ele1);
        if (cnt2 > n / 3) ans.push_back(ele2);
        return ans;
    }
};