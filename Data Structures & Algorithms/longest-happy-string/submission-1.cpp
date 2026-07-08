class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        string ans = "";
        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            int use = min(cnt1, 2);

            int n = ans.size();
            if (n >= 2 && ans[n-1] == ch1 && ans[n-2] == ch1) {
                if (pq.empty()) break;
                auto [cnt2, ch2] = pq.top(); pq.pop();
                ans += ch2;
                if (cnt2 - 1 > 0) pq.push({cnt2 - 1, ch2});
                pq.push({cnt1, ch1});
                continue;
            }
            for (int i = 0; i < use; i++) ans += ch1;
            if (cnt1 - use > 0) pq.push({cnt1 - use, ch1});
            }

        return ans;
    }
};