#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
   public:
    int maxDepth = 1;
    vector<int> vecs;
    void dfs(vector<NestedInteger> &nestedList, int depth) {
        maxDepth = max(maxDepth, depth);

        if (depth > vecs.size()) {
            vecs.push_back(0);
        }

        for (auto &n : nestedList) {
            if (n.isInteger()) {
                vecs[depth - 1] += n.getInteger();
            } else {
                vector<NestedInteger> v = n.getList();
                dfs(v, depth + 1);
            }
        }
    }

    int depthSumInverse(vector<NestedInteger> &nestedList) {
        dfs(nestedList, 1);
        int sum = 0;
        for (int i = 0; i < vecs.size(); i++) {
            sum += (maxDepth - (i + 1) + 1) * vecs[i];
        }

        return sum;
    }
};