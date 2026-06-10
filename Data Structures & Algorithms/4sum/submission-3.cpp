class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, long t) {
        sort(v.begin(), v.end());

        vector<vector<int>> res;
        for (int i = 0; i < v.size(); i++) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            for (int j = i + 1; j < v.size(); j++) {
                if (j > i + 1 && v[j] == v[j - 1]) continue;
                int l = j + 1, r = v.size() - 1;
                while (l < r) {
                    long sum = v[i] + v[j] + v[l] + v[r];
                    if (sum == t) {
                        res.push_back({v[i], v[j], v[l], v[r]});
                        l++;
                        r--;
                        while (l < r && v[l] == v[l - 1]) l++;
                    } else if (sum > t) r--;
                    else l++;
                }
            }
        }

        return res;
    }
};