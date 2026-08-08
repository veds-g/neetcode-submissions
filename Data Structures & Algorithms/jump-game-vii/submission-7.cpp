class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> reach(n, false);
        reach[0] = true;
        
        int windowCount = 0, l = -maxJump - 1, r = -minJump;
        for (int i = 1; i < n; i++) {
            l++, r++;
            if (l >= 0 and reach[l]) windowCount--; 
            if (r >= 0 and reach[r]) windowCount++;

            if (s[i] == '0' and windowCount > 0) reach[i] = true;
            
        }

        return reach[n - 1];
    }
};