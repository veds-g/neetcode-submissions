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
        if (n == 1) return true;

        DSU d(n);
        unordered_map<int, int> primeToIndex;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    if (primeToIndex.count(p))
                        d.unite(i, primeToIndex[p]);
                    else
                        primeToIndex[p] = i;
                    while (x % p == 0) x /= p;
                }
            }
            if (x > 1) {
                if (primeToIndex.count(x))
                    d.unite(i, primeToIndex[x]);
                else
                    primeToIndex[x] = i;
            }
        }

        int root = d.findPar(0);
        for (int i = 1; i < n; i++) {
            if (d.findPar(i) != root) return false;
        }

        return true;
    }
};