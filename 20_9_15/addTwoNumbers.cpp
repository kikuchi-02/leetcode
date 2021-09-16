

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *node;

    ListNode **current = &node;
    int up = 0;
    while (l1 || l2 || up > 0)
    {
      int s = up;
      up = 0;
      if (l1)
      {
        s += l1->val;
        l1 = l1->next;
      }
      if (l2)
      {
        s += l2->val;
        l2 = l2->next;
      }

      if (s > 9)
      {
        up += 1;
        s -= 10;
      }
      (*current) = new ListNode(s);
      current = &(*current)->next;
    }

    return node;
  }
};
