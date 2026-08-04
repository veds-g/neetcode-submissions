class DSU {
public:
    vector<int> p, sz;
    DSU(int n) {
        sz.resize(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    
    int findPar(int node) {
        if(p[node] == node) {
            return node;
        }
        
        return p[node] = findPar(p[node]);
    }
    
    void unite(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        
        if(pu == pv) return;
        
        if(sz[pu] < sz[pv]) swap(pu, pv);
        p[pv] = pu;
        sz[pu] += sz[pv];
    }

    bool connected(int n) {
        return *max_element(sz.begin(), sz.end()) == n;
    }
};

class Solution {
    int buildMST(int n, vector<vector<int>>& edges, int skip, int forceIdx) {
        DSU d(n);
        int wt = 0;

        // force edge first if specified
        if (forceIdx != -1) {
            d.unite(edges[forceIdx][0], edges[forceIdx][1]);
            wt += edges[forceIdx][2];
        }

        for (int j = 0; j < edges.size(); j++) {
            if (j == skip) continue;
            int u=edges[j][0], v=edges[j][1], w=edges[j][2];
            if (d.findPar(u) == d.findPar(v)) continue;
            d.unite(u, v);
            wt += w;
        }

        return d.connected(n) ? wt : INT_MAX;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        
        int baseWt = buildMST(n, edges, -1, -1);

        vector<int> critical, pseudo;
        for (int i = 0; i < edges.size(); i++) {
            int origIdx = edges[i][3];

            if (buildMST(n, edges, i, -1) > baseWt) {
                critical.push_back(origIdx);
            } else if (buildMST(n, edges, -1, i) == baseWt) {
                pseudo.push_back(origIdx);
            }
        }

        return {critical, pseudo};
    }
};