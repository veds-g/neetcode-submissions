class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        multiset<int> s(p.begin(), p.end());
        
        int ans  = 0;
        while (!s.empty()) {
            if (s.size() == 1) {
                ans++;
                break;
            }
            int first = *s.begin(), last = *s.rbegin();
            if (first + last <= l) {
                s.erase(s.begin());
            } 
            ans++;
            s.erase(prev(s.end()));
        }
        return ans;
    }
};