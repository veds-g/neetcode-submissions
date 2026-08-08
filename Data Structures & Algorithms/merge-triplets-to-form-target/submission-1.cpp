class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res(3, 0);
        for (auto& triplet : triplets) {
            bool aL = triplet[0] <= target[0];
            bool bL = triplet[1] <= target[1];
            bool cL = triplet[2] <= target[2];

            if (aL and bL and cL) {
                for (int i = 0; i < 3; i++) {
                    res[i] = max(res[i], triplet[i]);
                }
            } 
        }

        return res == target;
    }
};
