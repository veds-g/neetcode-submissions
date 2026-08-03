class Solution {
private:
    int hash(int r, int c, int factor) {
        return r * factor + c;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        unordered_map<int, vector<pair<int, int>>> edgeMap;

        int rows = heights.size(), cols = heights[0].size();
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < 4; k++) {
                    int r = i + dir[k][0], c = j + dir[k][1];
                    if (r < rows and r >= 0 and c < cols and c >= 0) {
                        int h1 = hash(i, j, cols);
                        int h2 = hash(r, c, cols);
                        int diff = abs(heights[i][j] - heights[r][c]);
                        edgeMap[h1].push_back({diff, h2});
                        edgeMap[h2].push_back({diff, h1});
                    }
                }
            }
        }

        vector<bool> vis(rows * cols, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});

        int ans = 0;
        while(!pq.empty()) {
            auto& [wt, node] = pq.top();
            pq.pop();

            if(vis[node] == true) continue;
            vis[node] = true;
            ans = max(ans, wt);
            if (node == rows * cols - 1) return ans;

            for(auto& nei : edgeMap[node]) {
                pq.push(nei);
            } 
        }

        return ans;
    }
};