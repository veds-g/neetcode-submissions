class DSU {
    vector<int> p, sz;
public:
    DSU(int n) {
        sz.resize(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int findPar(int n) {
        if (n == p[n]) return n;
        return p[n] = findPar(p[n]);
    }

    void unite(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if(sz[pu] < sz[pv]) swap(pu, pv);
        p[pv] = pu;
        sz[pu] += sz[pv];
    }
};

class Solution {
private:
    bool possible(int mid, vector<vector<int>>& grid, int n) {
        if (grid[0][0] > mid || grid[n-1][n-1] > mid) return false;

        DSU d(n * n);
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= mid) {
                    for (auto& dv : dir) {
                        int r = i + dv[0], c = j + dv[1];
                        if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] <= mid) {
                            d.unite(i * n + j, r * n + c);
                        }
                    }
                }
            }
        }

        return d.findPar(0) == d.findPar(n * n - 1);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mx = max(mx, grid[i][j]);
            }
        }

        int low = 0, high = mx, ans = mx;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, grid, n)) {
                ans = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
