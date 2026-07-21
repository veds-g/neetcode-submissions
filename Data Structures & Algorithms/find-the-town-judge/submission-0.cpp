class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> inEdge, outEdge;

        for(auto& x : trust) {
            inEdge[x[1]]++;
            outEdge[x[0]]++;
        }

        int cntN = 0, judge = -1;
        for(auto& [x, y] : inEdge) {
            if(y == n - 1 and !outEdge.count(x)) {
                cntN++;
                judge = x;
            }
        }
        return cntN > 1 ? -1 : judge;
    }
};