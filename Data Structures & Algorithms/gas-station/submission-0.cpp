class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIdx = 0, n = gas.size();

        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += gas[i] - cost[i];
            if (curr < 0) {
                startIdx = (i + 1) % n;
                curr = 0;
            } 
        }

        int total = 0;
        for (int i = startIdx; i < startIdx + n; i++) {
            int normalized = i % n;
            total += gas[normalized] - cost[normalized];
            if (total < 0) return -1;
        }

        return startIdx;
    }
};
