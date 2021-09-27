#include <bits/stdc++.h>

#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int>> hashmap;
        for (int i = 0; i < items.size(); i++) {
            hashmap[items[i][0]].push(items[i][1]);
        }
        vector<vector<int>> v = {};
        for (auto& m : hashmap) {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += m.second.top();
                m.second.pop();
            }
            int ave = sum / 5;

            v.push_back({m.first, ave});
        }
        sort(v.begin(), v.end());
        return v;
    }
};