#include <bits/stdc++.h>

#include <queue>
using namespace std;

class Solution {
   public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> track;
        track.push(make_pair(start[0], start[1]));

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> score(maze.size(), vector<int>(maze[0].size(), 0));

        int dis = INT_MAX;

        while (!track.empty()) {
            auto f = track.front();
            track.pop();

            for (auto& d : dir) {
                auto c = f;
                int count = score[f.first][f.second];
                while (c.first + d[0] >= 0 && c.first + d[0] < maze.size() && c.second + d[1] >= 0 && c.second + d[1] < maze[0].size() && maze[c.first + d[0]][c.second + d[1]] != 1) {
                    c.first += d[0];
                    c.second += d[1];
                    count++;
                }
                if (count == score[f.first][f.second]) {
                    continue;
                }
                if (score[c.first][c.second] == 0 || count < score[c.first][c.second]) {
                    score[c.first][c.second] = count;
                    if (c.first == destination[0] && c.second == destination[1]) {
                        dis = min(dis, count);
                    } else {
                        track.push(c);
                    }
                }
            }
        }
        if (dis == INT_MAX) {
            return -1;
        } else {
            return dis;
        }
    }
};
// TODO dijkstra