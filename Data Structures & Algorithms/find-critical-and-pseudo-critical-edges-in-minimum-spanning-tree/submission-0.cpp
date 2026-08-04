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
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        DSU mst(n);
        int wt = 0;
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (mst.findPar(u) == mst.findPar(v)) continue;
            else mst.unite(u, v), wt += w;
        } 

        vector<int> critical, pseudo;
        for(int i = 0; i < edges.size(); i++) {
            DSU mstC(n);
            int wtC = 0;
            for (int j = 0; j < edges.size(); j++) {
                if (i == j) continue;
                vector<int> edge = edges[j];
                int u = edge[0], v = edge[1], w = edge[2];
                if (mstC.findPar(u) == mstC.findPar(v)) continue;
                mstC.unite(u, v);
                wtC += w;
            }

            if (*max_element(mstC.sz.begin(), mstC.sz.end()) != n || wtC > wt) {
                critical.push_back(edges[i][3]);
                continue;
            } 

            DSU mstP(n);
            int wtP = 0;

            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            mstP.unite(u, v);
            wtP += w;

            for (int j = 0; j < edges.size(); j++) {
                if (i == j) continue;
                int eu = edges[j][0], ev = edges[j][1], ew = edges[j][2];
                if (mstP.findPar(eu) == mstP.findPar(ev)) continue;
                mstP.unite(eu, ev);
                wtP += ew;
            }

            if (wtP == wt) pseudo.push_back(edges[i][3]);
        }

        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo);
        return ans;
    }
};