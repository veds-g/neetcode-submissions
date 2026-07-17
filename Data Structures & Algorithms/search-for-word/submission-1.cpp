class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    bool found = search(i, j, board, 0, word);
                    if (found) return true;
                }
            }
        }

        return false;
    }

    bool search(int r, int c, vector<vector<char>>& board, int idx, string& word) {
        if (idx == word.size()) return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '#') return false;
        if (board[r][c] != word[idx]) return false;
        
        char temp = board[r][c];
        board[r][c] = '#';

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int R = r + dx[i], C = c + dy[i];
            if (search(R, C, board, idx + 1, word)) {
                return true;
            }
        }

        board[r][c] = temp;

        return false;
    }
};
