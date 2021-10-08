#include <bits/stdc++.h>

#include <unordered_set>
using namespace std;

class Solution {
   public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<string> dz = {"u", "d", "l", "r"};

    void dfs(vector<vector<int>>& grid, int i, int j, string& s) {
        grid[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            auto d = dirs[k];

            int i_dash = i + d[0];
            int j_dash = j + d[1];
            if (i_dash >= 0 && i_dash < grid.size() && j_dash >= 0 && j_dash < grid[0].size() && grid[i_dash][j_dash] >= 1) {
                s += dz[k];
                dfs(grid, i_dash, j_dash, s);
            }
        }
        s += "b";
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();

        unordered_set<string> hashset;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == 1) {
                    string s = "0";
                    dfs(grid, i, j, s);
                    if (hashset.find(s) == hashset.end()) {
                        hashset.insert(s);
                    }
                }
            }
        }
        return hashset.size();
    }
};