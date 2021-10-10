#include <bits/stdc++.h>

#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    unordered_map<TreeNode *, vector<TreeNode *>> hashmap;
    void dfs(TreeNode *node, TreeNode *parent) {
        if (node == nullptr) {
            return;
        }
        hashmap[node].push_back(parent);
        hashmap[parent].push_back(node);
        dfs(node->left, node);
        dfs(node->right, node);
    }

    int findClosestLeaf(TreeNode *root, int k) {
        dfs(root, nullptr);

        queue<TreeNode *> que;
        unordered_set<TreeNode *> hashset;

        for (auto it : hashmap) {
            if (it.first != nullptr && it.first->val == k) {
                que.push(it.first);
                hashset.insert(it.first);
            }
        }

        while (!que.empty()) {
            TreeNode *f = que.front();
            que.pop();
            if (f == nullptr) {
                continue;
            }
            if (hashmap[f].size() <= 1) {
                return f->val;
            }
            for (auto nei : hashmap[f]) {
                if (hashset.find(nei) == hashset.end()) {
                    que.push(nei);
                    hashmap[nei];
                }
            }
        }
        return 0;
    }
};

// TODO