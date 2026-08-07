class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> change;

        for (auto& x : bills) {
            if (x == 5) {
                change[5]++;
            } else if (x == 10) {
                if (change.contains(5)) {
                    change[5]--;
                    change[10]++;
                } else {
                    return false;
                }
            } else {
                if (change[10] >= 1 and change[5] >= 1) {
                    change[5]--;
                    change[10]--;
                } else if (change[5] >= 3) {
                    change[5] -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};