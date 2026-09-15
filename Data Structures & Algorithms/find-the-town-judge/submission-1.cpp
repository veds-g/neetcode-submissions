class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inEdge(n + 1), outEdge(n + 1);

        for(auto& x : trust) {
            inEdge[x[1]]++;
            outEdge[x[0]]++;
        }

        int cntN = 0, judge = -1;
        for(int i = 1; i <= n; i++) {
            if(inEdge[i] == n - 1 and !outEdge[i]) {
                cntN++;
                judge = i;
            }
        }
        return cntN > 1 ? -1 : judge;
    }
};