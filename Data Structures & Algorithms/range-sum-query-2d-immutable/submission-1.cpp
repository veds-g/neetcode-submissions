class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = matrix;
        int row = prefix.size(), col = prefix[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                prefix[i][j] += prefix[i][j - 1];
            }
        }
        for (int i = 0; i < col; i++) {
            for (int j = 1; j < row; j++) {
                prefix[j][i] += prefix[j - 1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2][col2] - 
            (col1 >= 1 ? prefix[row2][col1 - 1] : 0) - 
            (row1 >= 1 ? prefix[row1 - 1][col2] : 0) + 
            (row1 >= 1 and col1 >= 1 ? prefix[row1 - 1][col1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */