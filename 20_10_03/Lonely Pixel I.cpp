#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> candidates;
        vector<int> columns(picture[0].size());

        for (int i = 0; i < picture.size(); i++) {
            int count = 0;
            int idx = -1;
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B') {
                    count++;
                    idx = j;
                    columns[j]++;
                }
            }
            if (count == 1) {
                candidates.push_back(idx);
            }
        }

        int ans = 0;
        for (int i : candidates) {
            if (columns[i] == 1) {
                ans++;
            }
        }
        return ans;
    }
};