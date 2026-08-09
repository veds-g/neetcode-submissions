class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& is, vector<int>& ni) {
        vector<vector<int>> ans;

        int n = is.size(), i = 0;
        // exists before
        while (i < n and is[i][1] < ni[0]) {
            ans.push_back(is[i++]);
        }

        // merge
        while (i < n and is[i][0] <= ni[1]) {
            ni = {min(ni[0], is[i][0]), max(ni[1], is[i++][1])};
        }
        ans.push_back(ni);

        // exists after
        while (i < n) {
            ans.push_back(is[i++]);
        }

        return ans;
    }
};
