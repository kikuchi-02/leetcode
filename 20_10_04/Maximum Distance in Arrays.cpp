#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxDistance(vector<vector<int>>& arrays) {
        int dis = 0;
        int minNum = arrays[0][0];
        int maxNum = arrays[0][arrays[0].size() - 1];

        for (int i = 1; i < arrays.size(); i++) {
            auto array = arrays[i];
            dis = max(dis, max(maxNum - array[0], array[array.size() - 1] - minNum));
            maxNum = max(maxNum, array[array.size() - 1]);
            minNum = min(minNum, array[0]);
        }
        return dis;
    }
};