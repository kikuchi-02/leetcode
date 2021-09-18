
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

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
    int counter = 0;
    bool uniValue(TreeNode *node, int target)
    {
        if (node == nullptr)
        {
            return true;
        }
        bool leftUni = uniValue((*node).left, (*node).val);
        bool rightUni = uniValue((*node).right, (*node).val);

        if (!leftUni || !rightUni)
        {
            return false;
        }

        counter++;

        return (*node).val == target;
    }

    int countUnivalSubtrees(TreeNode *root)
    {
        uniValue(root, 1001);
        return counter;
    }
};