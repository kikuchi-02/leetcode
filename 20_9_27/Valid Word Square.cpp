#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words[i].size(); j++) {
                if (i == j) {
                    continue;
                }

                if (j >= words.size() || i >= words[j].size()) {
                    return false;
                }
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};