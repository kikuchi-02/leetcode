#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxVal = 0;

    void helper(TreeNode *node, int parent, int count)
    {
        if (node == nullptr)
        {
            maxVal = max(maxVal, count);
            return;
        }

        if (parent + 1 == node->val)
        {
            count++;
        }
        else
        {
            maxVal = max(maxVal, count);
            count = 1;
        }
        helper(node->left, node->val, count);
        helper(node->right, node->val, count);
    }

    int longestConsecutive(TreeNode *root)
    {
        helper(root, 3 * 1e4 + 1, 1);
        return maxVal;
    }
};