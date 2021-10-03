#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestLine(vector<vector<int>>& mat) {
        vector<int> horizontal(mat[0].size());
        vector<int> vertial(mat.size());
        vector<int> diagonal(mat.size() + mat[0].size() - 1);
        vector<int> antiDiagonal(mat.size() + mat[0].size() - 1);

        int row = mat.size();
        int column = mat[0].size();

        int dis = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    horizontal[j]++;
                    vertial[i]++;
                    diagonal[i - j + column - 1]++;
                    antiDiagonal[i + j]++;
                    dis = max(dis, max(horizontal[j], max(vertial[i], max(diagonal[i - j + column - 1], antiDiagonal[i + j]))));
                } else {
                    horizontal[j] = 0;
                    vertial[i] = 0;
                    diagonal[i - j + column - 1] = 0;
                    antiDiagonal[i + j] = 0;
                }
            }
        }
        return dis;
    }
};