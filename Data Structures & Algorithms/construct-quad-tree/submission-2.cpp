/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        bool check = checkForSplit(grid, n, 0, 0);

        if (!check) return new Node(grid[0][0], 1);
        return quad(grid, n, 0, 0);
    }

    bool checkForSplit(vector<vector<int>>& grid, int len, int x, int y) {
        int ele = grid[x][y];

        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                if (grid[x + i][y + j] != ele) {
                    return true;
                }
            }
        }

        return false;
    }

    Node* quad(vector<vector<int>>& grid, int n, int x, int y) {
        if (x >= grid.size() || y >= grid.size()) return NULL;

        Node* ans = new Node(grid[x][y], 0);

        int len = n / 2;
        int tlX = x, tlY = y;
        int trX = x, trY = y + len;
        int blX = x + len, blY = y;
        int brX = x + len, brY = y + len;

        bool tlC = checkForSplit(grid, len, tlX, tlY);
        if (tlC) {
            ans -> topLeft = quad(grid, len, tlX, tlY);
        } else {
            ans -> topLeft = new Node(grid[tlX][tlY], 1);
        }

        bool trC = checkForSplit(grid, len, trX, trY);
        if (trC) {
            ans -> topRight = quad(grid, len, trX, trY);
        } else {
            ans -> topRight = new Node(grid[trX][trY], 1);
        }

        bool blC = checkForSplit(grid, len, blX, blY);
        if (blC) {
            ans -> bottomLeft = quad(grid, len, blX, blY);
        } else {
            ans -> bottomLeft = new Node(grid[blX][blY], 1);
        }

        bool brC = checkForSplit(grid, len, brX, brY);
        if (brC) {
            ans -> bottomRight = quad(grid, len, brX, brY);
        } else {
            ans -> bottomRight = new Node(grid[brX][brY], 1);
        }

        return ans;
    }
};