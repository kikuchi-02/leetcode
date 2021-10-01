#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int maxCount = 0;
        int rowHits = 0;
        vector<int> columnHits(grid[0].size());

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 || grid[i - 1][j] == 'W') {
                    columnHits[j] = 0;
                    int itr = i;
                    while (itr < grid.size() && grid[itr][j] != 'W') {
                        if (grid[itr][j] == 'E') {
                            columnHits[j]++;
                        }
                        itr++;
                    }
                }

                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowHits = 0;
                    int itr = j;
                    while (itr < grid[0].size() && grid[i][itr] != 'W') {
                        if (grid[i][itr] == 'E') {
                            rowHits++;
                        }
                        itr++;
                    }
                }
                if (grid[i][j] == '0') {
                    int sum = rowHits + columnHits[j];
                    maxCount = max(maxCount, sum);
                }
            }
        }
        return maxCount;
    }
};