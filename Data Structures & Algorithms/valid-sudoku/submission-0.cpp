class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    if (s.contains(ch)) return false;
                    s.insert(ch);
                }
            }
            s.clear();
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[j][i];
                if (ch != '.') {
                    if (s.contains(ch)) return false;
                    s.insert(ch);
                }
            }
            s.clear();
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        char ch = board[i + k][j + l];
                        if (ch != '.') {
                            if (s.contains(ch)) return false;
                            s.insert(ch);
                        }
                    }
                }
                s.clear();
            }
        }

        return true;
    }
};
