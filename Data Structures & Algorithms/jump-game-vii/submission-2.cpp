class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> reach(n, false);
        reach[0] = true;

        for (int i = 1; i < n; i++) {
            if (s[i] == '1') continue;

            for (int j = max(0, i - maxJump); j <= min(n - 1, i - minJump); j++) {
                if (reach[j]) {
                    reach[i] = true;
                    break;
                }
            }
        }

        return reach[n - 1];
    }
};