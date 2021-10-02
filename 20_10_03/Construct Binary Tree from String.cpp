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
    TreeNode *helper(string s, int &i) {
        int current = 0;

        bool minus = s.at(i) == '-';
        if (minus) {
            i++;
        }
        while (i < s.size() && isdigit(s.at(i))) {
            current *= 10;
            current += s.at(i) - '0';
            i++;
        }
        if (minus) {
            current *= -1;
        }

        if (i >= s.size() || s.at(i) != '(') {
            return new TreeNode(current);
        }

        i += 1;
        TreeNode *left = helper(s, i);
        i += 1;

        TreeNode *right = nullptr;
        if (i < s.size() && s.at(i) == '(') {
            i += 1;
            right = helper(s, i);
            i += 1;
        }

        auto node = new TreeNode(current, left, right);
        return node;
    }

    TreeNode *str2tree(string s) {
        if (s.size() == 0) {
            return nullptr;
        }

        int i = 0;
        return helper(s, i);
    }
};

// TODO stack