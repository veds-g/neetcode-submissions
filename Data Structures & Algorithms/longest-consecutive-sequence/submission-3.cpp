class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int mx = 0, cnt = 0;
        while(s.size()) {
            int curr = *s.begin();
            cnt = 1;
            s.erase(curr);

            int currCopy = curr - 1;
            while(s.contains(currCopy)) {
                cnt++;
                s.erase(currCopy);
                currCopy--;
            }

            currCopy = curr + 1;
            while(s.contains(currCopy)) {
                cnt++;
                s.erase(currCopy);
                currCopy++;
            }

            mx = max(mx, cnt);
        }

        return mx;
    }
};
