class Solution {
public:
    vector<int> getConcatenation(vector<int>& v) {
        int n = v.size();
        vector<int> v1(2 * n);
        for (int i = 0; i < n; i++) v1[i] = v[i], v1[i + n] = v[i];
        return v1;
    }
};