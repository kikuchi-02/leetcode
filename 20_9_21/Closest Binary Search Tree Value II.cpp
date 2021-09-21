
#include <bits/stdc++.h>
#include <queue>
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

typedef pair<double, int> pi;

class Solution
{
public:
    priority_queue<pi, vector<pi>, greater<pi>> que;
    void helper(TreeNode *node, double target)
    {
        if (node == nullptr)
        {
            return;
        }
        que.push(make_pair(abs(target - (*node).val), (*node).val));
        helper((*node).left, target);
        helper((*node).right, target);
    }

    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        vector<int> result;
        helper(root, target);
        for (int i = 0; i < k; i++)
        {
            result.push_back(que.top().second);
            que.pop();
        }
        return result;
    }
};