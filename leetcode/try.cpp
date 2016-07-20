#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> sums;
    int row;
    int col;
    NumMatrix(vector<vector<int>> &matrix) {
        row = matrix.size();
        if (row == 0) return;
        col = matrix[0].size();
        if (col == 0) return;
        rows.resize(row, vector<int>(col, 0));
        cols.resize(row, vector<int>(col, 0));
        sums.resize(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            int tmp = 0;
            for (int j = 0; j < col; ++j) {
                tmp += matrix[i][j];
                rows[i][j] = tmp;
            }
        }
        for (int j = 0; j < col; ++j) {
            int tmp = 0;
            for (int i = 0; i < row; ++i) {
                tmp += matrix[i][j];
                cols[i][j] = tmp;
            }
        }
        for (int i = 0; i < row; ++i) {
            sums[i][0] = cols[i][0];
        }
        for (int j = 0; j < col; ++j) {
            sums[0][j] = rows[0][j];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                sums[i][j] = sums[i-1][j-1] + rows[i][j-1] + cols[i-1][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row == 0 || col == 0) return 0;
        if (row2 > row-1 || row1 > row-1 || col2 > col-1 || col1 > col-1)  return 0;
        int a = 0, b = 0, c = 0, d = 0;
        a = sums[row2][col2];
        if (row1-1 >= 0) b = sums[row1-1][col2];
        if (col1-1 >= 0) c = sums[row2][col1-1];
        if (row1-1 >= 0 && col1-1 >= 0) d = sums[row1-1][col1-1];
        int res = a - b - c + d;
        return res;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main() {
    vector<vector<int> > matrix{{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix m(matrix);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << m.sums[i][j] << " ";
        }
        cout << endl;
    }

    cout << m.sumRegion(2, 1, 4, 3) << endl;
    return 0;
}
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
