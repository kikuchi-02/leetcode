#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Solution {
   public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        unordered_map<int, int> hashmap;
        int count = 0;

        for (int top = 0; top < row; top++) {
            for (int left = 0; left < column; left++) {
                if (grid[top][left] != 1) {
                    continue;
                }
                for (int right = left + 1; right < column; right++) {
                    if (grid[top][right] != 1) {
                        continue;
                    }
                    int c = left * 200 + right;
                    count += hashmap[c];
                    hashmap[c]++;
                }
            }
        }

        return count;
    }
};