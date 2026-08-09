class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& is) {
        int n = is.size();

        vector<vector<int>> ans;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };
        sort(is.begin(), is.end(), cmp); 
        vector<int> ni = is[0];

        for (int i = 1; i < n; i++) {
            if (ni[1] < is[i][0]) {
                ans.push_back(ni);
                ni = is[i];
            } else if (is[i][1] < ni[0]) {
                ans.push_back(is[i]);
            } else {
                ni = {min(ni[0], is[i][0]), max(ni[1], is[i][1])};
            }
        }
        ans.push_back(ni);

        return ans;
    }
};
