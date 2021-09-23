#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
   public:
    vector<vector<int>> m;
    NumMatrix(vector<vector<int>>& matrix) {
        m = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0) {
                    m[i][j] = matrix[i][j];
                } else {
                    m[i][j] = matrix[i][j] + m[i - 1][j];
                }
            }
        }
    }

    void update(int row, int col, int val) {
        int v = m[row][col];
        if (row > 0) {
            v -= m[row - 1][col];
        }

        for (int i = row; i < m.size(); i++) {
            m[i][col] += val - v;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int j = col1; j <= col2; j++) {
            s += m[row2][j];
            if (row1 > 0) {
                s -= m[row1 - 1][j];
            }
        }
        return s;
    }
};
// TODO Binary Indexed Tree

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */