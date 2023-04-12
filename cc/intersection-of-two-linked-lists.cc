// http://leetcode.com/problems/intersection-of-two-linked-lists/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int l1 = len(headA);
    int l2 = len(headB);
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    if (l1 > l2) {
      int diff = l1 - l2;
      while (diff--) {
        p1 = p1->next;
      }
    } else if (l2 > l1) {
      int diff = l2 - l1;
      while (diff--) {
        p2 = p2->next;
      }
    }
    while (p1 && p2) {
      if (p1 == p2) {
        return p1;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    return nullptr;
  }

private:
  int len(ListNode *head) {
    int ret = 0;
    while (head) {
      head = head->next;
      ret++;
    }
    return ret;
  }
};
