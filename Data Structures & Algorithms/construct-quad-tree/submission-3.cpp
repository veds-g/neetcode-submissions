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
        return quad(grid, n, 0, 0);
    }

    Node* quad(vector<vector<int>>& grid, int n, int x, int y) {
        if (n == 1) {
            return new Node(grid[x][y], 1);
        }

        Node* ans = new Node(grid[x][y], 0);

        int len = n / 2;
        Node* tl = quad(grid, len, x, y);
        Node* tr = quad(grid, len, x, y + len);
        Node* bl = quad(grid, len, x + len, y);
        Node* br = quad(grid, len, x + len, y + len);

        if (tl -> isLeaf and tr -> isLeaf and bl -> isLeaf and br -> isLeaf and 
        tl -> val == tr -> val and tr -> val == bl -> val and bl -> val == br -> val) {
            bool val = tl -> val;
            delete tl; delete tr; delete bl; delete br;

            return new Node(val, 1); 
        }

        return new Node(tl -> val, 0, tl, tr, bl, br);
    }
};