class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& is, vector<int>& ni) {
        vector<vector<int>> ans;

        int n = is.size(), flag = 0;
        for(int i = 0; i < n; i++) {
            vector<int>& curr = is[i];

            // exists before
            if (ni[1] < curr[0]) {
                flag = 1;
                ans.push_back(ni);
                ni = {INT_MAX, INT_MAX};
                ans.push_back(curr);
            }
            // exists after
            else if (curr[1] < ni[0]) {
                ans.push_back(curr);
            }
            // merge
            else {
                ni = {min(ni[0], curr[0]), max(ni[1], curr[1])};
            }
        }
        if (!flag) ans.push_back(ni);

        return ans;
    }
};
