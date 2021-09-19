
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
    int closestValue(TreeNode *root, double target)
    {
        int maxV = INT_MAX, minV = INT_MIN;
        while (root != nullptr)
        {
            if ((*root).val < target)
            {
                minV = (*root).val;
                root = (*root).right;
            }
            else
            {
                maxV = (*root).val;
                root = (*root).left;
            }
        }
        if (abs(minV - target) > abs(maxV - target))
        {
            return maxV;
        }
        else
        {
            return minV;
        }
    }
};
// TODO approach 2