class DSU {
    vector<int> size, parent;
public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findPar(parent[node]);
    } 

    void unionNodes(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) swap(pu, pv);
        
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();

        DSU d(rows * cols + 1);
        int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] != 'O') continue;
                if (i == 0 or j == 0 or i == rows -1 or j == cols - 1) {   
                    d.unionNodes(rows * cols, i * cols + j);
                } else {
                    for (int k = 0; k < 4; k++) {
                        int r = i + dir[k][0], c = j + dir[k][1];
                        if (board[r][c] == 'O') {
                            d.unionNodes(i * cols + j, r * cols + c);
                        }
                    }
                }
            }
        }


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' and d.findPar(rows * cols) != d.findPar(i * cols + j)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

