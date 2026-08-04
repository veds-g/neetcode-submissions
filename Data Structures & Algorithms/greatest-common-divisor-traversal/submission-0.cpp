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
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DSU d(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(nums[i], nums[j]) > 1) {
                    d.unite(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (d.findPar(i) != d.findPar(j)) {
                    return false;
                }
            }
        }

        return true;
    }
};