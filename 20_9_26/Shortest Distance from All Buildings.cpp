#include <bits/stdc++.h>

#include <queue>
using namespace std;

class Solution {
   public:
    int shortestDistance(vector<vector<int>>& grid) {
        int dir[4][2] = {{0, 1},
                         {0, -1},
                         {1, 0},
                         {-1, 0}};

        int minDist = INT_MAX;
        int emptyCounter = 0;

        int row = grid.size();
        int column = grid[0].size();

        vector<vector<int>> totalCount = vector<vector<int>>(row, vector<int>(column, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                minDist = INT_MAX;

                queue<pair<int, int>> que;
                int step = 0;
                que.push(make_pair(i, j));
                while (que.size() > 0) {
                    step++;
                    int queSize = que.size();
                    for (int k = 0; k < queSize; k++) {
                        auto pos = que.front();
                        que.pop();

                        for (auto& d : dir) {
                            int nextRow = pos.first + d[0];
                            int nextColumn = pos.second + d[1];

                            if (nextRow >= 0 && nextRow < row && nextColumn >= 0 && nextColumn < column && grid[nextRow][nextColumn] == emptyCounter) {
                                grid[nextRow][nextColumn]--;
                                totalCount[nextRow][nextColumn] += step;
                                minDist = min(minDist, totalCount[nextRow][nextColumn]);
                                que.push({nextRow, nextColumn});
                            }
                        }
                    }
                }
                emptyCounter--;
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};