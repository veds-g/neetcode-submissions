class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!pq.empty()) {
            vector<int> temp = pq.top(); pq.pop();
            int diff = temp[0], r = temp[1], c = temp[2];

            if (r == rows - 1 and c == cols - 1) {
                return diff;
            }

            if (dist[r][c] < diff) continue;
            for (int k = 0; k < 4; k++) {
                int newR = r + dir[k][0], newC = c + dir[k][1];
                if (newR < 0 || newC < 0 || newR >= rows || newC >= cols) {
                    continue;
                }

                int newDiff = max(diff, abs(heights[r][c] - heights[newR][newC]));
                if (newDiff < dist[newR][newC]) {
                    dist[newR][newC] = newDiff;
                    pq.push({newDiff, newR, newC});
                }
            }
        }

        return -1;
    }
};