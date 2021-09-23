#include <bits/stdc++.h>
using namespace std;

class UnionFind {
   public:
    vector<int> root;
    vector<int> rank;
    int count;

    UnionFind(int sz) {
        count = 0;
        root = vector<int>(sz, -1);
        rank = vector<int>(sz, 0);
    }

    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else {
                root[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }
    void setVal(int x) {
        root[x] = x;
        count++;
    }
};

class Solution {
   public:
    void landNumber(int i, int j, int m, int n, UnionFind &uf, int pos) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        int index = i * n + j;
        if (uf.root[index] > -1) {
            uf.unionSet(index, pos);
        }
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>> &positions) {
        vector<int> result;

        UnionFind uf(m * n);

        for (int i = 0; i < positions.size(); i++) {
            vector<int> pos = positions[i];

            int index = pos[0] * n + pos[1];
            if (uf.root[index] == -1) {
                uf.setVal(index);

                landNumber(pos[0] - 1, pos[1], m, n, uf, index);
                landNumber(pos[0] + 1, pos[1], m, n, uf, index);
                landNumber(pos[0], pos[1] - 1, m, n, uf, index);
                landNumber(pos[0], pos[1] + 1, m, n, uf, index);
            }

            result.push_back(uf.count);
        };
        return result;
    }
};