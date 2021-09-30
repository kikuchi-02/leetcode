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

struct Pos {
    int maxNum, minNum, count;
};

class Solution {
   public:
    int result = 0;
    Pos helper(TreeNode *node) {
        Pos p;
        if (node == nullptr) {
            p.count = 0;
            return p;
        }

        p.count = 1;

        auto l = helper(node->left);
        auto r = helper(node->right);

        if (l.count == -1) {
            return l;
        } else if (l.count == 0) {
            p.minNum = node->val;
        } else {
            if (node->val <= l.maxNum) {
                p.count = -1;
                return p;
            }
            p.count += l.count;
            p.minNum = l.minNum;
        }

        if (r.count == -1) {
            return r;
        } else if (r.count == 0) {
            p.maxNum = node->val;
        } else {
            if (node->val >= r.minNum) {
                p.count = -1;
                return p;
            }
            p.count += r.count;
            p.maxNum = r.maxNum;
        }

        result = max(result, p.count);
        return p;
    }
    int largestBSTSubtree(TreeNode *root) {
        helper(root);
        return result;
    }
};