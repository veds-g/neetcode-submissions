class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        ans.push_back(temp);
        addSubsets(nums, 0, temp);
        return ans;
    }

    void addSubsets(vector<int>& nums, int idx, vector<int>& temp) {
        if (idx == nums.size()) return;

        // 2 choices
        
        // skip curr
        addSubsets(nums, idx + 1, temp);

        // add to subset
        temp.push_back(nums[idx]);
        ans.push_back(temp);
        addSubsets(nums, idx + 1, temp);
        temp.pop_back();
    }
};
