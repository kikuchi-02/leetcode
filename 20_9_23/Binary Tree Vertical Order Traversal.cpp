#include <bits/stdc++.h>

#include <queue>
#include <unordered_map>
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

typedef pair<int, vector<int>> pi;

class Solution {
   public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        unordered_map<int, vector<int>> hashmap;

        queue<pair<int, TreeNode *>> que;
        que.push(make_pair(0, root));

        int minC = 0, maxC = 0;

        while (que.size() > 0) {
            auto f = que.front();
            que.pop();
            if (f.second == nullptr) {
                continue;
            }
            hashmap[f.first].push_back(f.second->val);
            minC = min(minC, f.first);
            maxC = max(maxC, f.first);
            que.push(make_pair(f.first - 1, f.second->left));
            que.push(make_pair(f.first + 1, f.second->right));
        }

        if (hashmap.size() == 0) {
            return {};
        }

        vector<vector<int>> result;
        for (int i = minC; i <= maxC; i++) {
            result.push_back(hashmap[i]);
        }

        return result;
    }
};