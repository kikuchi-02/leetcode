#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
   public:
    Node* h;
    bool initial = true;
    void helper(Node* node, int insertVal) {
        Node* next = node->next;
        if (initial) {
            initial = false;
        } else if (h == next) {
            node->next = new Node(insertVal, next);
            return;
        }

        if (node->val <= next->val && node->val <= insertVal && insertVal <= next->val || node->val > next->val && (insertVal <= next->val || insertVal >= node->val)) {
            node->next = new Node(insertVal, next);
            return;
        }

        helper(next, insertVal);
    }

    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }

        h = head;
        helper(head, insertVal);

        return head;
    }
};