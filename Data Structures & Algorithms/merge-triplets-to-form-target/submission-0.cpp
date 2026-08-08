class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a, b, c;
        a = b = c = false;

        for (auto& triplet : triplets) {
            // match
            bool aM = triplet[0] == target[0];
            bool bM = triplet[1] == target[1];
            bool cM = triplet[2] == target[2];
            bool aL = triplet[0] <= target[0];
            bool bL = triplet[1] <= target[1];
            bool cL = triplet[2] <= target[2];

            if (aM and bM and cM) {
                return true;
            } else if (aM and bM and cL) {
                a = b = true;
            } else if (aM and cM and bL) {
                a = c = true;
            } else if (bM and cM and aL) {
                b = c = true;
            } else if (aM and bL and cL) {
                a = true;
            } else if (aL and bM and cL) {
                b = true;
            } else if (aL and bL and cM) {
                c = true;
            }

            // check exit
            if (a and b and c) {
                return true;
            }
        }

        return false;
    }
};
