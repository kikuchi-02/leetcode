#include <bits/stdc++.h>
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
    vector<vector<int>> result;

    int helper(TreeNode *node) {
        if (node == nullptr) {
            return -1;
        }

        int l = helper(node->left);
        int r = helper(node->right);
        int depth = max(l, r) + 1;

        if (result.size() > depth) {
            result[depth].push_back(node->val);
        } else {
            result.push_back({node->val});
        }

        return depth;
    }
    vector<vector<int>> findLeaves(TreeNode *root) {
        if (root->left != nullptr) {
            helper(root->left);
        }
        if (root->right != nullptr) {
            helper(root->right);
        }
        result.push_back({root->val});
        return result;
    }
};