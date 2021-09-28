#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* helper(ListNode* node, int num) {
        while (node != nullptr && num > 0) {
            node = node->next;
            num--;
        }
        return node;
    }
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        bool f = true;

        ListNode* node = head;
        while (node != nullptr) {
            if (f) {
                node = helper(node, m - 1);
            } else {
                node->next = helper(node, n + 1);
                node = node->next;
            }
            f = !f;
        }
        return head;
    }
};