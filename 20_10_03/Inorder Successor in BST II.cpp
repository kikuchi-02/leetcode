#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
   public:
    Node* inorderSuccessor(Node* node) {
        if (node->right != nullptr) {
            node = node->right;
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        } else if (node->parent != nullptr) {
            int current = node->val;
            while (node->parent != nullptr) {
                node = node->parent;
                if (node->val > current) {
                    return node;
                }
            }
            return nullptr;

        } else {
            return nullptr;
        }
    }
};