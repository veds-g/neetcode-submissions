class Solution {
public:
    int totalNQueens(int n) {
        vector<string> nq(n, string(n, '.'));
        int ans = 0;
        backtrack(ans, nq, 0);
        return ans;
    }

    void backtrack(int& ans, vector<string>& nq, int r) {
        if (r == nq.size()) {
            ans++;
            return;
        }
        for (int c = 0; c < nq.size(); c++) {
            if (canPlace(r, c, nq)) {
                nq[r][c] = 'Q';
                backtrack(ans, nq, r + 1);
                nq[r][c] = '.';
            }
        }
    }

    bool canPlace(int r, int c, vector<string>& board) {
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};