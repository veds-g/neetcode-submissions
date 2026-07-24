class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    bool unionNodes(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        
        if(pu == pv) {
            return true;
        }

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];

        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU graph(n);
        
        for(auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if(graph.unionNodes(node1, node2)) {
                return edge;
            }
        }

        return vector<int>{};
    }
};
