#include <bits/stdc++.h>

#include <queue>
using namespace std;

class Solution {
   public:
    pair<int, int> helper(vector<vector<int>>& maze, pair<int, int> position, int row, int col) {
        while (true) {
            int nextRow = position.first + row;
            int nextColumn = position.second + col;
            if (nextRow >= 0 && nextRow < maze.size() && nextColumn >= 0 && nextColumn < maze[0].size() && maze[nextRow][nextColumn] != 1) {
                position.first = nextRow;
                position.second = nextColumn;
            } else {
                break;
            }
        }
        return position;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> que;
        que.push(make_pair(start[0], start[1]));
        vector<vector<int>> dir = {{0, 1},
                                   {0, -1},
                                   {1, 0},
                                   {-1, 0}};

        while (!que.empty()) {
            maze[que.front().first][que.front().second] = -1;
            for (auto& d : dir) {
                auto pos = helper(maze, que.front(), d[0], d[1]);
                if (maze[pos.first][pos.second] != -1) {
                    if (destination[0] == pos.first && destination[1] == pos.second) {
                        return true;
                    }

                    que.push(pos);
                }
            }
            que.pop();
        }
        return false;
    }
};