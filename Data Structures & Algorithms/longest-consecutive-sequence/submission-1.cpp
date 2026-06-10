class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int mx = 0, cnt = 0;
        while (s.size()) {
            int curr = *s.begin(), currCopy = curr - 1;\
            s.erase(curr);
            cnt = 1;
            while (s.contains(currCopy)) cnt++, s.erase(currCopy--);
            currCopy = curr + 1;
            while (s.contains(currCopy)) cnt++, s.erase(currCopy++);
            cout << cnt << endl;
            mx = max(mx, cnt);\
        }
        return mx;

    }
};
