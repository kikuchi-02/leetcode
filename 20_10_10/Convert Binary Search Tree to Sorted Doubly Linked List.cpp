#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
   public:
    Node* dfs(Node* node) {
        if (node == nullptr) return nullptr;

        Node* left = dfs(node->left);
        Node* right = dfs(node->right);

        Node* current = node;
        current->right = right;
        if (right != nullptr) {
            right->left = current;
        }

        if (left == nullptr) {
            current->left = nullptr;
            return current;
        } else {
            left->left = nullptr;
            Node* tmp = left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            tmp->right = current;
            current->left = tmp;
            return left;
        }
    }

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* node = dfs(root);
        Node* tmp = node;
        while (tmp->right != nullptr) {
            tmp = tmp->right;
        }
        tmp->right = node;
        node->left = tmp;
        return node;
    }
};