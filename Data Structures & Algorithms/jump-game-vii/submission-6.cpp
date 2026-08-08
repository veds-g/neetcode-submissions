class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> reach(n, false);
        reach[0] = true;
        
        int windowCount = 0;
        for (int i = 1; i < n; i++) {
            if (i - maxJump - 1 >= 0 and reach[i - maxJump - 1]) windowCount--; 
            if (i - minJump >= 0 and reach[i - minJump]) windowCount++;

            if (s[i] == '0' and windowCount > 0) reach[i] = true;
            
        }

        return reach[n - 1];
    }
};