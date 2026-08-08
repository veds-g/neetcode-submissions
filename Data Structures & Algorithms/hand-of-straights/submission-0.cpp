class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz) {
        int n = hand.size();
        if (n % sz != 0) return false;

        map<int, int> mp;
        for(auto& x : hand) mp[x]++;
        
        while (!mp.empty()) {
            auto [ele, cnt] = *mp.begin();
            for (int i = 0; i < sz; i++) {
                int curr = ele + i;
                if (mp.contains(curr)) {
                    mp[curr]--;
                    if (mp[curr] == 0) mp.erase(curr);
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
