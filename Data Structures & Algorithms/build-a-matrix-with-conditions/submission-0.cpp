class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<vector<int>> ans;

        unordered_map<int, vector<int>> rg, cg;
        unordered_map<int, int> ri, ci;

        for(auto& r : rc) {
            rg[r[0]].push_back(r[1]);
            ri[r[1]]++;
        }

        for(auto& c : cc) {
            cg[c[0]].push_back(c[1]);
            ci[c[1]]++;
        }

        unordered_map<int, int> finalR, finalC;
        queue<int> rq, cq;

        for (int i = 1; i <= k; i++) {
            if (ri[i] == 0) rq.push(i);
            if (ci[i] == 0) cq.push(i);
        }

        int idx = 0;
        while (rq.size()) {
            int ele = rq.front(); rq.pop();

            finalR[ele] = idx++;

            for (auto& nei : rg[ele]) {
                ri[nei]--;
                if (ri[nei] == 0) rq.push(nei);
            }
        }
        if (finalR.size() < k) return ans;

        idx = 0;
        while (cq.size()) {
            int ele = cq.front(); cq.pop();

            finalC[ele] = idx++;

            for (auto& nei : cg[ele]) {
                ci[nei]--;
                if (ci[nei] == 0) cq.push(nei);
            }
        }
        if (finalC.size() < k) return ans;

        ans.resize(k, vector<int>(k, 0));
        for(int i = 1; i <= k; i++) {
            ans[finalR[i]][finalC[i]] = i;
        }

        return ans;
    }
};