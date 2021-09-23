#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector<int>> matrix(mat1.size(), vector<int>(mat2[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int counter = 0;
                for (int k = 0; k < mat1[i].size(); k++) {
                    counter += mat1[i][k] * mat2[k][j];
                }
                matrix[i][j] = counter;
            }
        }
        return matrix;
    }
};