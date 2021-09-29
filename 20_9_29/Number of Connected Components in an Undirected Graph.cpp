#include <bits/stdc++.h>
using namespace std;

class UnionFind {
   public:
    vector<int> root;
    vector<int> rank;
    int count;
    UnionFind(int N) : root(N), rank(N) {
        for (int i = 0; i < N; i++) {
            root[i] = i;
            rank[i] = 1;
        }
        count = N;
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootX] = rootY;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootY] = rootX;
            } else {
                root[rootX] = rootY;
                rank[rootX]++;
            }
            count--;
        }
    }
};

class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto& e : edges) {
            uf.unionSet(e[0], e[1]);
        }
        return uf.count;
    }
};