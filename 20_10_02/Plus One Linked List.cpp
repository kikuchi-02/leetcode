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
    int dfs(ListNode* node) {
        if (node->next == nullptr) {
            node->val += 1;
            if (node->val > 9) {
                node->val -= 10;
                return 1;
            }
            return 0;
        }

        int res = dfs(node->next);
        node->val += res;
        if (node->val > 9) {
            node->val -= 10;
            return 1;
        }
        return 0;
    }
    ListNode* plusOne(ListNode* head) {
        if (dfs(head) > 0) {
            head = new ListNode(1, head);
        }
        return head;
    }
};