#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class UnionFind {
   public:
    vector<int> root;
    vector<int> rank;
    unordered_map<string, int> hashmap;

    int add(string x) {
        if (hashmap.find(x) != hashmap.end()) {
            return hashmap[x];
        }

        int sz = root.size();
        root.push_back(sz);
        rank.push_back(0);
        hashmap[x] = sz;
        return sz;
    }

    int find(int x) {
        if (x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    void unionSet(string x, string y) {
        int xi = add(x);
        int yi = add(y);
        int rootX = find(xi);
        int rootY = find(yi);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool connected(string x, string y) {
        int xi = add(x);
        int yi = add(y);
        int rootX = find(xi);
        int rootY = find(yi);
        return rootX == rootY;
    }
};

class Solution {
   public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }

        UnionFind uf;
        for (auto& sims : similarPairs) {
            uf.unionSet(sims[0], sims[1]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] != sentence2[i] && !uf.connected(sentence1[i], sentence2[i])) {
                return false;
            }
        }
        return true;
    }
};