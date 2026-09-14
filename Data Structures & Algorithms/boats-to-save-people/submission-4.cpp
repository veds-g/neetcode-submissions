class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;

        int cnt = 0;
        while (l <= r) {
            int curr = limit - people[r--];
            if (curr >= people[l]) {
                l++;
            }
            cnt++;
        }
        return cnt;         
    }
};