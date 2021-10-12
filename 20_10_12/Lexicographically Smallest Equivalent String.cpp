#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> root;
    vector<int> rank;

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX < rootY) {
            root[rootY] = rootX;
        } else if (rootX > rootY) {
            root[rootX] = rootY;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; i++) {
            root.push_back(i);
            rank.push_back(0);
        }

        for (int i = 0; i < s1.size(); i++) {
            unionSet(s1[i] - 'a', s2[i] - 'a');
        }
        for (int i = 0; i < baseStr.size(); i++) {
            baseStr.at(i) = find(baseStr.at(i) - 'a') + 'a';
        }
        return baseStr;
    }
};