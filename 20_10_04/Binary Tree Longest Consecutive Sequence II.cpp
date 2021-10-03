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
    int result = 0;
    pair<int, int> helper(TreeNode *node) {
        if (node == nullptr) {
            return make_pair(0, 0);
        }
        auto left = helper(node->left);
        auto right = helper(node->right);

        if (node->left == nullptr) {
            left.first = 1;
            left.second = 1;
        } else {
            int v = node->left->val;
            if (node->val - 1 == v) {
                left.first += 1;
                left.second = 1;
            } else if (node->val + 1 == v) {
                left.first = 1;
                left.second += 1;
            } else {
                left.first = 1;
                left.second = 1;
            }
        }

        if (node->right == nullptr) {
            right.first = 1;
            right.second = 1;
        } else {
            int v = node->right->val;
            if (node->val - 1 == v) {
                right.first += 1;
                right.second = 1;
            } else if (node->val + 1 == v) {
                right.first = 1;
                right.second += 1;
            } else {
                right.first = 1;
                right.second = 1;
            }
        }

        result = max(result, max(left.first + right.second - 1, left.second + right.first - 1));

        pair<int, int> res;
        res.first = max(left.first, right.first);
        res.second = max(left.second, right.second);
        return res;
    }
    int longestConsecutive(TreeNode *root) {
        helper(root);
        return result;
    }
};