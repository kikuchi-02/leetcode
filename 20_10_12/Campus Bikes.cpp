#include <bits/stdc++.h>

#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> result(workers.size(), -1);
        unordered_set<int> workerSet;
        vector<bool> used_bikes(bikes.size(), false);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;

        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                que.push(make_pair(dis, make_pair(i, j)));
            }
        }

        while (!que.empty() && workerSet.size() < result.size()) {
            auto d = que.top();
            que.pop();
            int w = d.second.first;
            int b = d.second.second;
            if (result[w] == -1 && !used_bikes[b]) {
                workerSet.insert(w);
                result[w] = b;
                used_bikes[b] = true;
            }
        }
        return result;
    }
};