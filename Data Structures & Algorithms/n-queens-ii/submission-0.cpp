class Solution {
public:
    int totalNQueens(int n) {
        vector<string> nq(n, string(n, '.'));
        vector<vector<string>> ans;
        backtrack(ans, nq, 0);
        return ans.size();
    }

    void backtrack(vector<vector<string>>& ans, vector<string>& nq, int r) {
        if (r == nq.size()) {
            ans.push_back(nq);
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