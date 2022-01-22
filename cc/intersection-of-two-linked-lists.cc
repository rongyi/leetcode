// http://leetcode.com/problems/intersection-of-two-linked-lists/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int la = len(headA);
    int lb = len(headB);
    auto *p = headA;
    auto *q = headB;
    if (la > lb) {
      auto diff = la - lb;
      while (diff) {
        p = p->next;
        diff--;
      }
    } else if (la < lb) {
      auto diff = lb - la;
      while (diff) {
        q = q->next;
        diff--;
      }
    }
    while (p && q) {
      if (p == q) {
        return p;
      }
      p = p->next;
      q = q->next;
    }
    return nullptr;
  }

private:
  int len(ListNode *head) {
    int ret = 0;
    while (head) {
      ++ret;
      head = head->next;
    }
    return ret;
  }
};
