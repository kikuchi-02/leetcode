#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> v;
        for (int i = 0; i < text.size(); i++) {
            for (string word : words) {
                int j = i + word.size() - 1;
                if (text.substr(i, word.size()) == word) {
                    v.push_back({i, j});
                }
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};