#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *closest = nullptr;

        TreeNode *current = root;
        while (current != nullptr)
        {
            if (current->val > p->val)
            {
                if (closest == nullptr || abs(closest->val - p->val) > abs(current->val - p->val))
                {
                    closest = current;
                }

                current = current->left;
            }
            else if (current->val == p->val)
            {
                current = current->right;
            }
            else
            {
                current = current->right;
            }
        }
        return closest;
    }
};